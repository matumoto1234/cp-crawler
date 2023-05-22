// detail: https://atcoder.jp/contests/abc223/submissions/37128876
use proconio::input;

fn main() {
    input! {
        N: usize,
        ABs: [(f64, f64); N],
    };

    let mut all_time = 0f64;

    for AB in ABs.iter() {
        let A = AB.0;
        let B = AB.1;

        all_time += A / B;
    }

    let mut time = all_time / 2f64;
    let mut sum_dist = 0f64;

    for AB in ABs.iter() {
        let A = AB.0;
        let B = AB.1;

        // time < A/B
        if time * B < A {
            sum_dist += time * B;
            break;
        } else {
            time -= A / B;
            sum_dist += A;
        }
    }

    println!("{}", sum_dist);
}
