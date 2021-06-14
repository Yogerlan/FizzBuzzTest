public class FizzBuzzTest {

    /**
     * Prints the numbers from "start" to "end". But for multiples of "fizz" print
     * "Fizz" instead of the number and for the multiples of "buzz" print "Buzz".
     * For numbers which are multiples of both "fizz" and "buzz" print "FizzBuzz".
     *
     * @param fizz Prints "Fizz" if the list index is divisible by "fizz".
     * @param buzz Prints "Buzz" if the list index is divisible by "buzz".
     * @param start Starting iteration index.
     * @param end Ending iteration index.
     * 
     * The list can be filled in ascendent or descendent order.
     */
    public static void fizzbuzz(int fizz, int buzz, int start, int end) {
        String fb;
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                fb = (i % fizz) == 0 || (i % buzz == 0)
                   ? (i % fizz == 0 ? "Fizz" : "") + (i % buzz == 0 ? "Buzz" : "")
                   : Integer.toString(i);
                System.out.println(fb);
            }
        } else {
            for (int i = start; i >= end; i--) {
                fb = (i % fizz) == 0 || (i % buzz == 0)
                   ? (i % fizz == 0 ? "Fizz" : "") + (i % buzz == 0 ? "Buzz" : "")
                   : Integer.toString(i);
                System.out.println(fb);
            }
        }
    }

    public static void main(String[] args) {
        int fizz = 3;
        int buzz = 5;
        int start = 1;
        int end = 100;
        boolean validate = false;

        // Get fizz, buzz, start & end params from command line arguments.
        for (int a = 0; a < args.length; a++) {
            if (args[a].equals("-f")) {
                fizz = Integer.parseInt(args[a + 1]);
            }
            if (args[a].equals("-b")) {
                buzz = Integer.parseInt(args[a + 1]);
            }
            if (args[a].equals("-s")) {
                start = Integer.parseInt(args[a + 1]);
            }
            if (args[a].equals("-e")) {
                end = Integer.parseInt(args[a + 1]);
            }
            if (args[a].equals("-v")) {
                validate = true;
            }
        }

        fizzbuzz(fizz, buzz, start, end);

        if (!validate) {
            System.out.print("Press ENTER to continue...");
            System.console().readLine();
        }
    }

}
