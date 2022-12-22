// detail: https://atcoder.jp/contests/abc237/submissions/37443405
use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        a_matrix: [[i64; w]; h],
    }

    let mut b_matrix = vec![vec![0i64; h]; w];
    for i in 0..w {
        for j in 0..h {
            b_matrix[i][j] = a_matrix[j][i];
        }
    }

    for i in 0..w {
        for j in 0..h {
            if j > 0 {
                print!(" ");
            }
            print!("{}", b_matrix[i][j]);
        }
        println!()
    }
}
