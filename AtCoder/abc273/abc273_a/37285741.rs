// detail: https://atcoder.jp/contests/abc273/submissions/37285741
use proconio::input;

fn f(n: i64) -> i64 {
    if n == 0 {
        return 1;
    }
    return n * f(n - 1);
}

fn main() {
    input! {
        n: i64,
    }

    println!("{}", f(n));
}
