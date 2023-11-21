import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class SharedResource {
    static final int BUFFER_SIZE = 5;
    static Queue<Integer> buffer = new LinkedList<>();
    static Lock mutex = new ReentrantLock();
    static Semaphore emptySem = new Semaphore(BUFFER_SIZE);
    static Semaphore fullSem = new Semaphore(0);
}

class Producer extends Thread {
    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                int item = random.nextInt(100);
                SharedResource.emptySem.acquire();
                SharedResource.mutex.lock();
                SharedResource.buffer.add(item);
                System.out.println("Produced " + item + ". Buffer: " + SharedResource.buffer);
                SharedResource.mutex.unlock();
                SharedResource.fullSem.release();
                Thread.sleep(random.nextInt(500) + 100); // Sleep for a random time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                SharedResource.fullSem.acquire();
                SharedResource.mutex.lock();
                int item = SharedResource.buffer.poll();
                System.out.println("Consumed " + item + ". Buffer: " + SharedResource.buffer);
                SharedResource.mutex.unlock();
                SharedResource.emptySem.release();
                Thread.sleep(random.nextInt(500) + 100); // Sleep for a random time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ProducerConsumerExample {
    public static void main(String[] args) {
        Thread producerThread = new Producer();
        Thread consumerThread = new Consumer();

        producerThread.start();
        consumerThread.start();
    }
}
