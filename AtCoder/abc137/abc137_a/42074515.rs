// detail: https://atcoder.jp/contests/abc137/submissions/42074515
use proconio::input;
use std::cmp;

fn main() {
    input! {
        a: i32,
        b: i32,
    };

    println!("{}", cmp::max(a + b, cmp::max(a - b, a * b)));
}
