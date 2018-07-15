public class Knapsack01 {

    public int calculate(int val[], int wt[], int W){
        int K[][] = new int[val.length][W+1];
        for(int i=0;i<val.length;i++){
        	K[i][0]=0;
        }
        for(int j=0;j<W+1;j++){
        	K[0][j]=1;
        }
        K[0][0]=0;
        
        for(int i=1; i < val.length; i++){
            for(int j=1; j <= W; j++){
//                if(i == 0 || j == 0){
//                    K[i][j] = 0;
//                    continue;
//                }
                if(j - wt[i] >= 0){
                    K[i][j] = Math.max(K[i-1][j], K[i-1][j-wt[i]] + val[i]);
                }else{
                    K[i][j] = K[i-1][j];
                }
            }
        }
        return K[val.length-1][W];
    }
    
    public static void main(String args[]){
        Knapsack01 k = new Knapsack01();
        int val[] = {1,4,5,7};
        int wt[] = {1,3,4,5};
        int r = k.calculate(val, wt, 7);
        System.out.print(r);
    }
}