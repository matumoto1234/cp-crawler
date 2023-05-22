// detail: https://atcoder.jp/contests/APG4b/submissions/37285170
use proconio::input;

fn main() {
    input! {
        p: usize,
    }

    if p == 1 {
        input! {
            price: i64,
            N: i64,
        }
        println!("{}", price * N);
    }

    if p == 2 {
        input! {
            text: String,
            price: i64,
            N: i64,
        }
        println!("{}!", text);
        println!("{}", price * N);
    }
}
