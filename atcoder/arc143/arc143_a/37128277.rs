// detail: https://atcoder.jp/contests/arc143/submissions/37128277
use proconio::input;

fn main() {
    input! {
        A: i64,
        B: i64,
        C: i64,
    };

    let mut xs = vec![A, B, C];
    xs.sort();

    if xs[0] + xs[1] + xs[2] == 1 {
        println!("-1");
        return;
    }

    if xs[2] - xs[1] == 0 {
        println!("{}", xs[0] - 1 + xs[1] - 1 + 1);
    } else if xs[2] - xs[1] == 1 {
        println!("{}", xs[0] - 1 + xs[1] - 1 - (xs[0] - 1) + 2);
    } else {
        println!("-1");
    }
}
