// detail: https://atcoder.jp/contests/abc281/submissions/37285962
use proconio::input;

fn main() {
    input! {
        n: i64,
    }

    for i in (0..=n).rev() {
        println!("{}", i);
    }
}
