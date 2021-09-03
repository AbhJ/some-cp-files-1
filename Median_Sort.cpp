import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.IntStream;
public class Solution {
 static final int koita = 100;
 static final int cn = 10000;
 static final Random RANDOM = new Random();
 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 int T = sc.nextInt();
 sc.nextInt();
 for (int tc = 1; tc <= T; ++tc) {
 String[] c = new String[koita];
 for (int i = 0; i < c.length; ++i) {
 c[i] = sc.next();
 }
 System.out.println(String.format("Case #%d: %d", tc, solve(c)));
 }
 sc.close();
 }
 static int solve(String[] c) {
 int[] playerCorrectNums =
 Arrays.stream(c)
 .mapToInt(s -> (int) s.chars().filter(ch -> ch == '1').count())
 .toArray();
 int[] a =
 IntStream.range(0, koita)
 .boxed()
 .sorted(Comparator.comparing(i -> playerCorrectNums[i]))
 .mapToInt(x -> x)
 .toArray();
 double[] s = new double[koita];
 for (int i = 0; i < s.length; ++i) {
 s[a[i]] = -3 + 6.0 / (koita - 1) * i;
 }
 int[] questionCorrectNums =
 IntStream.range(0, cn)
 .map(
 i ->
 (int)
 Arrays.stream(c).filter(outcome -> outcome.charAt(i) == '1').count())
 .toArray();
 int[] b =
 IntStream.range(0, cn)
 .boxed()
 .sorted(Comparator.comparing(i -> questionCorrectNums[i]))
 .mapToInt(x -> x)
 .toArray();
 double[] q = new double[cn];
 for (int i = 0; i < q.length; ++i) {
 q[b[i]] = 3 - 6.0 / (cn - 1) * i;
 }
 int[] arra = new int[koita];
 for (int i = 1; i < koita - 1; ++i) {
 arra[i] =
 simulate(
 q,c[a[i]],s[a[i]],c[a[i - 1]],s[a[i - 1]],c[a[i + 1]],s[a[i + 1]]);
 }
 System.err.println(Arrays.toString(Arrays.stream(arra).sorted().toArray()));
 int[] sortedDiffs =
 Arrays.stream(arra).boxed().sorted(Comparator.reverseOrder()).mapToInt(x -> x).toArray();
 if (sortedDiffs[0] - sortedDiffs[1] >= 50) {
 return a[
 IntStream.range(1, koita - 1).boxed().max(Comparator.comparing(i -> arra[i])).get()]
 + 1;
 }
 int maxPlayerCorrectNums = Arrays.stream(playerCorrectNums).max().getAsInt();
 return IntStream.range(0, c.length)
 .filter(i -> playerCorrectNums[i] == maxPlayerCorrectNums)
 .findAny()
 .getAsInt()
 + 1;
 }
 static int simulate(
 double[] q,
 String outcome,
 double s,
 String prevOutcome,
 double prevS,
 String nextOutcome,
 double nextS) {
 return (int)
 IntStream.range(0, cn)
 .filter(
 i -> s - q[i] >= 1 && outcome.charAt(i) == '0' && prevOutcome.charAt(i) == '1')
 .count();
 }
}