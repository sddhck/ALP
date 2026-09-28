//SUBMISSÃO # 48774854
//Submissão: 28/04/2026 08:35:06

#include <stdio.h>
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF){
        int e30 = 0, e31 = 0, e32 = 0, e33 = 0, e34 = 0, e35 = 0, e36 = 0, e37 = 0, e38 = 0, e39 = 0, 
            e40 = 0, e41 = 0, e42 = 0, e43 = 0, e44 = 0, e45 = 0, e46 = 0, e47 = 0, e48 = 0, e49 = 0, 
            e50 = 0, e51 = 0, e52 = 0, e53 = 0, e54 = 0, e55 = 0, e56 = 0, e57 = 0, e58 = 0, e59 = 0, e60 = 0,
            d30 = 0, d31 = 0, d32 = 0, d33 = 0, d34 = 0, d35 = 0, d36 = 0, d37 = 0, d38 = 0, d39 = 0, 
            d40 = 0, d41 = 0, d42 = 0, d43 = 0, d44 = 0, d45 = 0, d46 = 0, d47 = 0, d48 = 0, d49 = 0,
            d50 = 0, d51 = 0, d52 = 0, d53 = 0, d54 = 0, d55 = 0, d56 = 0, d57 = 0, d58 = 0, d59 = 0, d60 = 0;
        int size, pares = 0;
        char lado;

        for (int i = 0; i < n; i++)
        {
            scanf("%d %c", &size, &lado);
            switch (size)
            {
                case 30: lado == 'E' ? e30++ : d30++; break;
                case 31: lado == 'E' ? e31++ : d31++; break;
                case 32: lado == 'E' ? e32++ : d32++; break;
                case 33: lado == 'E' ? e33++ : d33++; break;
                case 34: lado == 'E' ? e34++ : d34++; break;
                case 35: lado == 'E' ? e35++ : d35++; break;
                case 36: lado == 'E' ? e36++ : d36++; break;
                case 37: lado == 'E' ? e37++ : d37++; break;
                case 38: lado == 'E' ? e38++ : d38++; break;
                case 39: lado == 'E' ? e39++ : d39++; break;
                case 40: lado == 'E' ? e40++ : d40++; break;
                case 41: lado == 'E' ? e41++ : d41++; break;
                case 42: lado == 'E' ? e42++ : d42++; break;
                case 43: lado == 'E' ? e43++ : d43++; break;
                case 44: lado == 'E' ? e44++ : d44++; break;
                case 45: lado == 'E' ? e45++ : d45++; break;
                case 46: lado == 'E' ? e46++ : d46++; break;
                case 47: lado == 'E' ? e47++ : d47++; break;
                case 48: lado == 'E' ? e48++ : d48++; break;
                case 49: lado == 'E' ? e49++ : d49++; break;
                case 50: lado == 'E' ? e50++ : d50++; break;
                case 51: lado == 'E' ? e51++ : d51++; break;
                case 52: lado == 'E' ? e52++ : d52++; break;
                case 53: lado == 'E' ? e53++ : d53++; break;
                case 54: lado == 'E' ? e54++ : d54++; break;
                case 55: lado == 'E' ? e55++ : d55++; break;
                case 56: lado == 'E' ? e56++ : d56++; break;
                case 57: lado == 'E' ? e57++ : d57++; break;
                case 58: lado == 'E' ? e58++ : d58++; break;
                case 59: lado == 'E' ? e59++ : d59++; break;
                case 60: lado == 'E' ? e60++ : d60++;
            }
        }
        size = (d30 < e30) ? d30 : e30;
        size += (d31 < e31) ? d31 : e31;
        size += (d32 < e32) ? d32 : e32;
        size += (d33 < e33) ? d33 : e33;
        size += (d34 < e34) ? d34 : e34;
        size += (d35 < e35) ? d35 : e35;
        size += (d36 < e36) ? d36 : e36;
        size += (d37 < e37) ? d37 : e37;
        size += (d38 < e38) ? d38 : e38;
        size += (d39 < e39) ? d39 : e39;
        size += (d40 < e40) ? d40 : e40;
        size += (d41 < e41) ? d41 : e41;
        size += (d42 < e42) ? d42 : e42;
        size += (d43 < e43) ? d43 : e43;
        size += (d44 < e44) ? d44 : e44;
        size += (d45 < e45) ? d45 : e45;
        size += (d46 < e46) ? d46 : e46;
        size += (d47 < e47) ? d47 : e47;
        size += (d48 < e48) ? d48 : e48;
        size += (d49 < e49) ? d49 : e49;
        size += (d50 < e50) ? d50 : e50;
        size += (d51 < e51) ? d51 : e51;
        size += (d52 < e52) ? d52 : e52;
        size += (d53 < e53) ? d53 : e53;
        size += (d54 < e54) ? d54 : e54;
        size += (d55 < e55) ? d55 : e55;
        size += (d56 < e56) ? d56 : e56;
        size += (d57 < e57) ? d57 : e57;
        size += (d58 < e58) ? d58 : e58;
        size += (d59 < e59) ? d59 : e59;
        size += (d60 < e60) ? d60 : e60;

        printf("%d\n", size);
    }

    return 0;
}