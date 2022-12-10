// detail: https://atcoder.jp/contests/abc279/submissions/37127635
use proconio::input;

fn main() {
    input! {
        S: String,
    };

    let mut count: i32 = 0;

    for ch in S.as_str().chars() {
        if ch == 'v' {
            count += 1;
        } else {
            count += 2;
        }
    }
    println!("{}", count);
}
