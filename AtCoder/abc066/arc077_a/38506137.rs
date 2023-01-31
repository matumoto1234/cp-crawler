// detail: https://atcoder.jp/contests/abc066/submissions/38506137
use proconio::input;
use std::collections::VecDeque;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut reverse_flag = false;
    let mut b: VecDeque<i64> = VecDeque::new();

    a.iter().for_each(|ai| {
        if reverse_flag {
            b.push_front(ai.clone());
        } else {
            b.push_back(ai.clone());
        }
        reverse_flag = !reverse_flag;
    });

    if reverse_flag {
        b.iter().rev().for_each(|bi| {
            print!("{} ", bi);
        })
    } else {
        b.iter().for_each(|bi| {
            print!("{} ", bi);
        })
    }
}
