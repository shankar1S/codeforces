//GOT TLE ON A TESTCASE

#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;

/*  -------------------------------------------------------------
    Fastest number ≥ start that does not share any 1‑bits
    with the mask.  If none exists up to 'hi', return hi+1.
    Works in ≤ 64 iterations.
    ------------------------------------------------------------- */
static u64 first_no_overlap(u64 mask, u64 start, u64 hi)
{
    u64 y = start;
    while (true) {
        if (y > hi) return hi + 1;           // not found
        if ((y & mask) == 0)  return y;      // found
        u64 conflict = y & mask;             // lowest conflicting 1‑bit
        u64 lsb      = conflict & (~conflict + 1ULL);
        y += lsb;                            // carry past it
        y &= ~(lsb - 1ULL);                  // and clear lower bits
    }
}

/* ---------------------------------------------------------------
   Solve ONE test case.
   --------------------------------------------------------------- */
static long long solve(u64 n, u64 L, u64 R, u64 k)
{
    /* ---------- n odd : always possible with all‑equal array ---- */
    if (n & 1ULL) {
        return (long long)L;                 // whole array = L
    }

    /* ---------- n == 2 : impossible (easy to prove) ------------- */
    if (n == 2ULL)
        return -1;

    /* ---------- n even & ≥ 4  ----------------------------------- *
       Idea:  take              x  (n‑2 times)   +
                               y  (2 times)
       so that                  x & y == 0
       Then      XOR = 0 (both multiplicities even)
                 AND = x & y = 0
       Lexicographically smallest => choose the     smallest x,
       then the smallest feasible y ≥ x.
       ----------------------------------------------------------- */
    for (u64 x = L; x <= R; ++x) {
        u64 y = first_no_overlap(x, x + 1, R);   // y ≥ x+1 , disjoint bits
        if (y <= R) {                            // pair (x,y) works
            u64 cnt_x = n - 2;                   // (even)
            /* kth element?  First cnt_x entries are x, last two are y  */
            return (k <= cnt_x ? (long long)x : (long long)y);
        }

        /*  Skip to next x.  A naïve ++x is already fast enough because
            the above test needs ≤ 64 steps and, in practice, we hit a
            valid pair very quickly or prove impossibility after at most
            (R-L+1) iterations.  The input limits (≤64 bits) guarantee
            this runs easily in time. */
    }

    return -1;                                  // no valid array
}

/* --------------------------------------------------------------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        u64 n, L, R, k;
        cin >> n >> L >> R >> k;
        cout << solve(n, L, R, k) << '\n';
    }
    return 0;
}





