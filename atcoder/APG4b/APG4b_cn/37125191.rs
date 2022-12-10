// detail: https://atcoder.jp/contests/APG4b/submissions/37125191
use proconio::input;

fn main() {
    input!{
        x: i64,
        a: i64,
        b: i64,
    };

    let ans1 = x+1;
    println!("{}", ans1);

    let ans2 = ans1 * (a+b);
    println!("{}", ans2);

    let ans3 = ans2 * ans2;
    println!("{}", ans3);

    let ans4 = ans3 - 1;
    println!("{}", ans4);
}
