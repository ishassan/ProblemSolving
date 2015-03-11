#include <stdio.h>

const int MAX_LENGTH = 18;
const int MAX_SUM = 162;
const int MAX_SQUARE_SUM = 1458;
int primes[1460];
unsigned long long dyn_table[20][164][1460];
//changed here.......1
unsigned long long ans[19][180][1482];  //about 45 MB

int start[19][163];
int end[19][163];
//upto here.........1
void gen_primes() {
    for (int i = 0; i <= MAX_SQUARE_SUM; ++i) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= MAX_SQUARE_SUM; ++i) {
        if (!primes[i]) {
            continue;
        }
        for (int j = 2; i * j <= MAX_SQUARE_SUM; ++j) {
            primes[i*j] = 0;
        }
    }
}

void gen_table() {
    for (int i = 0; i <= MAX_LENGTH; ++i) {
        for (int j = 0; j <= MAX_SUM; ++j) {
            for (int k = 0; k <= MAX_SQUARE_SUM; ++k) {
                dyn_table[i][j][k] = 0;
            }
        }
    }
    dyn_table[0][0][0] = 1;

    for (int i = 0; i < MAX_LENGTH; ++i) {
        for (int j = 0; j <= 9 * i; ++j) {
            for (int k = 0; k <= 9 * 9 * i; ++k) {
                for (int l = 0; l < 10; ++l) {
                    dyn_table[i + 1][j + l][k + l*l] += dyn_table[i][j][k];
                }
            }
        }
    }
}

unsigned long long count_lucky (unsigned long long maxp) {
    unsigned long long result = 0;
    int len = 0;
    int split_max[MAX_LENGTH];
    while (maxp) {
        split_max[len] = maxp % 10;
        maxp /= 10;
        ++len;
    }
    int sum = 0;
    int sq_sum = 0;
    unsigned long long step_result;
    unsigned long long step_;
    for (int i = len-1; i >= 0; --i) {
        step_result = 0;
        int x1 = 9*i;
        for (int l = 0; l < split_max[i]; ++l) {
            //changed here........2
            step_ = 0;
            if(ans[i][sum+l][sq_sum+l*l]!=0)
            {
                step_result +=ans[i][sum+l][sq_sum+l*l];
                continue;
            }
            int y = l + sum;
            int x = l*l + sq_sum;
            for (int j = 0; j <= x1; ++j) {
                if(primes[j + y])
                    for (int k=start[i][j]; k<=end[i][j]; ++k) {
                        if (primes[k + x]) {
                            step_result += dyn_table[i][j][k];
                            step_+=dyn_table[i][j][k];
                        }
                    }

            }
            ans[i][sum+l][sq_sum+l*l] = step_;
            //upto here...............2
        }
        result += step_result;
        sum += split_max[i];
        sq_sum += split_max[i] * split_max[i];
    }

    if (primes[sum] && primes[sq_sum]) {
        ++result;
    }

    return result;
}

int main(int argc, char** argv) {
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
//#endif


    gen_primes();
    gen_table();

    //changed here..........3
    for(int i=0;i<=18;i++)
        for(int j=0;j<=163;j++)
        {
            for(int k=0;k<=1458;k++)
                if(dyn_table[i][j][k]!=0ll)
                {
                    start[i][j] = k;
                    break;
                }

            for(int k=1460;k>=0;k--)
                if(dyn_table[i][j][k]!=0ll)
                {
                    end[i][j]=k;
                    break;
                }
        }
    //upto here..........3
    int cases = 0;
    scanf("%d",&cases);
    for (int i = 0; i < cases; ++i) {
        unsigned long long a, b;

        scanf("%lld %lld", &a, &b);
        //changed here......4
        if(b == 1000000000000000000ll)
            b--;
        //upto here.........4
        printf("%lld\n", count_lucky(b) - count_lucky(a-1));
    }
    return 0;

}

