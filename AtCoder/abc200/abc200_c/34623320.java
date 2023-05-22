// detail: https://atcoder.jp/contests/abc200/submissions/34623320
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.Collectors;

public class Main {
    public static int binomial(int a, int b) {
        int result = 1;
        for (int i = 0; i < b; i++) {
            result *= a - i;
            result /= i + 1;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int n = Integer.parseInt(stdin.nextLine());
        List<Integer> as = Arrays.stream(stdin.nextLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        List<Integer> asMod200 = as
                .stream().map(a -> a % 200)
                .collect(Collectors.toList());

        TreeMap<Integer, Integer> counter = new TreeMap<Integer, Integer>();
        asMod200.forEach(a -> {
            counter.merge(a, /*default=*/1, Integer::sum);
        });

//        TreeMap<Integer, Integer> counter = asMod200.stream().collect(Collectors.groupingBy(), (map, a) -> map.merge(a, 1, (key, count) -> count + 1), TreeMap::putAll);

        int ans = counter
                .values()
                .stream()
                .map((count)->binomial(count, 2))
                .reduce(0, Integer::sum);

        System.out.println(ans);
    }
}
