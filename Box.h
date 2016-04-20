class Box{
    public:
        Box(int inputWidth, int inputHeight);
        ~Box();
        int getArea();
    private:
        int width;
        int height;
};
