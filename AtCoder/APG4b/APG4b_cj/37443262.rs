// detail: https://atcoder.jp/contests/APG4b/submissions/37443262
use proconio::input;

fn main() {
    input! {
        n: i64,
        a_list: [i64; n],
    }

    let sum = a_list.iter().sum::<i64>();
    let avg = sum / n;

    a_list.iter().for_each(|a| {
        println!("{}", (a - avg).abs());
    })
}
