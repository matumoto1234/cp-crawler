// detail: https://atcoder.jp/contests/abc276/submissions/38504715
use proconio::input;

fn main() {
    input! {
        s: String,
    }

    match s.rfind('a') {
        Some(i) => println!("{}", i + 1),
        None => println!("-1"),
    }
}
