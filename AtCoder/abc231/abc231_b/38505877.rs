// detail: https://atcoder.jp/contests/abc231/submissions/38505877
use std::collections::BTreeMap;
use proconio::input;

fn main() {
    input! {
        n: usize,
        s: [String; n],
    }

    let mut counter: BTreeMap<String, i64> = BTreeMap::new();

    s.iter().for_each(|si| {
        let count = counter.entry(si.clone()).or_insert(0);
        *count += 1;
    });

    let (ans, _) = counter.iter().fold(("".to_string(), 0 as i64), |a, b| {
        let (a_key, a_val) = a;
        let (b_key, b_val) = b;
        if a_val > *b_val {
            (a_key, a_val)
        } else {
            (b_key.clone(), *b_val)
        }
    });

    println!("{}", ans);
}
