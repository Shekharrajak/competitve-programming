#include<stdio.h>
#include<sys/sem.h>
#include<pthread.h>

#define MAXCHAIRS    4

int            nextCustomerNo = 1;
int            first = 0, last = 0;
int            waitingCustomerCount = 0;
pthread_mutex_t        lck;
pthread_cond_t        custCond[MAXCHAIRS];
int            custNos[MAXCHAIRS];
pthread_cond_t        brbrCond;

void WakeUpBarber()
{
    pthread_cond_signal(&brbrCond);
}

void CustomerWait(int chair)
{
    pthread_cond_wait(&custCond[chair], &lck);   
}

int CheckVacancyAndWait(void)
{
    int chair;
    int custNo;
   
    // Check if vacnt chair is available or not
    // If available wait otherwise leave.
    pthread_mutex_lock(&lck);
    if (waitingCustomerCount == MAXCHAIRS)
    {
        pthread_mutex_unlock(&lck);
        return 0;
    }
    else
    {
        chair = last;
        custNo = custNos[chair] = nextCustomerNo++;
        last = (chair + 1) % MAXCHAIRS;
        waitingCustomerCount++;

        // If this is the first customer then wakeup the barber
        if (waitingCustomerCount == 1)
            WakeUpBarber();
   
        // Wait for service   
        CustomerWait(chair);
        pthread_mutex_unlock(&lck);
        return custNo;
    }
}

int CheckCustomerAndSleep(void)
{
    // Check if any customer is waiting in the chair
    pthread_mutex_lock(&lck);
    if (waitingCustomerCount == 0)
        pthread_cond_wait(&brbrCond, &lck);

    // Don't release mutex here
    // Mutex is relased after gaining access to the next waiting customer.
}

void ServiceCustomer()
{
    int custNo;
    int chair;

    // The mutex is already in locked state.
    chair = first;
    first = (first + 1) % MAXCHAIRS;
    custNo = custNos[chair];
    waitingCustomerCount--;

    // Inform the custmenr being serviced
    pthread_cond_signal(&custCond[chair]);
    pthread_mutex_unlock(&lck);

    // Service takes time
    printf("Barber servicing %d customer\n",custNo);
    sleep(3);
}

void *Barber(void *k)
{
    while (1)
    {
        // Check for any customer waiting
        // and if no custmer is there sleep
        CheckAndSleep();

        // Customer is available or new customer has wakeup
        ServiceCustomer();
    }
}

void * Customer(void)
{
    int custno;
    while (1)
    {
        // Customer arrived, check for vacant seat and wait.
        // If no vacancy then leave.
        custno = CheckVacancyAndWait();

        if (custno != 0)
        {
            // Getting serviced
            printf("Customer %d getting serviced ...\n",custno);
            sleep(3);
        }
        else
        {
            printf("No chair is vacant and customer leaving ...\n");
            sleep((time(NULL) % 5) + 1);
        }
    }
}

int main(void)
{
    Initialize();
    pthread_t brbr, cust[MAXCHAIRS+1];

    // Create barber thread
    pthread_create(&brbr, NULL, Barber, 0);

    // Create  MAXCHAIRS + 1 customer threads.
    for (int i=0;  i<MAXCHAIRS+1; i++)
        pthread_create(&cust[i], NULL, *Customer, NULL);
   
    // Do nothing here
    for ( ; ; )
        ;
    return 0;
}

//================================== Sem
