class helloJNI {
    private native void print();
    public static void main(String[] args) {
        new helloJNI().print();
    }
    static {
        System.loadLibrary("hellojni");
    }
}
