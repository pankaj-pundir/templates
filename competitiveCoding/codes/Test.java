/**
 * test
 */
public class Test implements Runnable {

    static int  val = 0;
    String message;

    Test(String message) {
        this.message = message;
    }

    public void run() {

        for(int i = 0; i < 10; i++) {
        System.out.println(String.format("message -> %s %s",
        message, ++val).getBytes());
        }
    }

    public static void main(String[] args) {
        Thread test = new Thread(new Test("test1"));
        Thread test2 = new Thread(new Test("test2"));

        test.start();
        test2.start();
    }
    
}