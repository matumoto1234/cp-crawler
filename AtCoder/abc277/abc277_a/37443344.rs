// detail: https://atcoder.jp/contests/abc277/submissions/37443344
use proconio::input;

fn main() {
    input! {
        n: usize,
        x: i64,
        p_list: [i64; n],
    }

    for i in 0..n {
        if p_list[i] == x {
            println!("{}", i + 1);
            break;
        }
    }
}
