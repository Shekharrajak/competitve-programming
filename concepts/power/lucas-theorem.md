If MOD is a prime number, and N has base MOD representation (aj,...,a1,a0) and r has base MOD representation (bj,...,b1,b0), then (N CHOOSE R) is congruent [mod MOD] to

(N choose R) modulus MOD = ((aj CHOOSE bj)...(a1 CHOOSE b1) (a0 CHOOSE b0)) modulus MOD

Let me make it more clear with example, for instance you have answer as (588 choose 277) % 5, then


 **(588 choose 277) % 5 = ?
                Representation of 588 in base of 5 = 4323
                Representation of 277 in base of 5 = 2102
                Now your answer reduces to = ((4 choose 2)(3 choose 1)(2 choose 0)(3 choose 2)) % 5
                                         = (6 * 3 * 1 * 3) % 5
                                         = 54 % 5
                                         = 4**
                          
## Refer : 

- https://brilliant.org/wiki/lucas-theorem/
