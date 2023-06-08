// detail: https://atcoder.jp/contests/arc018/submissions/42074630
use proconio::input;

fn main() {
    input! {
        height: f64,
        bmi: f64,
    };

    println!("{:.8}", bmi * height * height / 10000.0);
}
