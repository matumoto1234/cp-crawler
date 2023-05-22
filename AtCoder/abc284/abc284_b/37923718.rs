// detail: https://atcoder.jp/contests/abc284/submissions/37923718
use proconio::input;

fn solve() {
    input!{
        n: usize,
        a: [i64; n],
    }

    let mut odd_count = 0;

    for i in 0..n{
        if a[i] % 2== 1{
            odd_count += 1;
        }
    }

    println!("{}", odd_count);
}

fn main(){
    input!{
        t: usize,
    }
    for _ in 0..t {
        solve();
    }
}