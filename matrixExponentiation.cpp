const ll mod = 1e9+7;
using matrix = vector<vector<ll>>;
int k; //size of square matrix

// computes A x B
matrix mult(matrix A, matrix B) {
    
    matrix C(k+1, vector<ll>(k+1));
    
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; ++j) {
            for(int l = 1; l <= k; ++l) {
                C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % mod;
            }
        }
    }
    
    return C;
}

// compute A ^ p
matrix power(matrix A, int p) {
    
    if(p == 1) {
        return A;
    } else if(p % 2 == 1) {
        return mult(A, power(A, p-1));
    } else {
        matrix X = power(A, p/2);
        return mult(X, X);
    }
    
}

int main() {
    
    int n; //the fifth Fibonacci number
    k = 2;
    
    while(scanf("%d", &n) == 1) {
    
        vector<ll> F(k+1, 0);
        F[1] = 1;
        F[2] = 1;
        
        matrix T(k+1, vector<ll>(k+1, 0));
        T[1][1] = 1; T[1][2] = 1;
        T[2][1] = 1; T[2][2] = 0;

        if(n == 1) {
            printf("1\n");
        }
        
        // raise to the power of (n-1)th
        T = power(T, n-2);

        ll ans = 0; // first column of new states matrix
        for(int i = 0; i <= k; ++i) {
            ans += (T[1][i] * F[i]) % mod;
        }
        
        printf("%lld\n", ans);
        
    }
    
    return 0;
}
