// detail: https://atcoder.jp/contests/abc080/submissions/42074540
use proconio::input;
use std::cmp;

fn main() {
    input! {
        n: i32,
        a: i32,
        b: i32,
    };

    println!("{}", cmp::min(a*n, b));
}
