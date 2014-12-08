/**
 * This is the demo code for BinaryBuffer class
 * Last update: 8/12/2014
 * @author fahmy
 */
public class Demo {
    public static void main(String args[]){
        BinaryBuffer buffer1 = new BinaryBuffer();
        for (int i = 0; i < 5; i++) {
            buffer1.add(true);
        }
        for (int i = 0; i < 5; i++) {
            buffer1.add(false);
        }
        for (int i = 0; i < 5; i++) {
            buffer1.add(true);
        }
        buffer1.print();

        BinaryBuffer bufferCopy = new BinaryBuffer(buffer1);
        for (int i = 0; i < 7; i++) {
            bufferCopy.pop();
        }
        bufferCopy.print();

        String digest = bufferCopy.toString();
        try{

            BinaryBuffer bufferFromString = new BinaryBuffer(digest);
            bufferFromString.add((byte)'a');
            bufferFromString.print();
            byte[] bytes = {'a','b','c'};
            bufferFromString.add(bytes);
            bufferFromString.print();

        }catch(Exception e){

            System.out.println(e.getMessage());

        }
    }
}
