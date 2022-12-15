// detail: https://atcoder.jp/contests/APG4b/submissions/37285534
use proconio::input;

fn main() {
    input!{
        n: usize,
        mut a: i64,
    }

    for i in 1..=n {
        input!{
            op: char,
            b: i64,
        }

        if op == '/' && b == 0 {
            println!("error");
            break;
        }

        if op == '+' {
            a += b;
        } else if op == '-' {
            a -= b;
        } else if op == '*' {
            a *= b;
        } else if op == '/' {
            a /= b;
        }
        println!("{}:{}", i, a)
    }
}
