// detail: https://atcoder.jp/contests/abc256/submissions/37285577
use proconio::input;

fn main() {
    input! {
        n: i64,
    }

    let mut prod = 1;

    for _ in 0..n {
        prod *= 2;
    }
    println!("{}", prod);
}
