// detail: https://atcoder.jp/contests/APG4b/submissions/38505748
use std::collections::BTreeMap;
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut counter: BTreeMap<i64, i64> = BTreeMap::new();

    a.iter().for_each(|ai| {
        let count = counter.entry(*ai).or_insert(0);
        *count += 1;
    });

    let ans = counter.iter().fold((0 as i64, 0 as i64), |a, b| {
        let (a_key, a_val) = a;
        let (b_key, b_val) = b;
        if a_val > *b_val {
            (a_key, a_val)
        } else {
            (*b_key, *b_val)
        }
    });

    println!("{} {}", ans.0, ans.1);
}
