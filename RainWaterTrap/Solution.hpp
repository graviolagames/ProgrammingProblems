class Solution
{
    public:
    Solution();
    ~Solution();
    int RainWaterTrapped(int *elevations, int len);
    private:
    enum elements{NOTHING,WATER,TERRAIN,MAX};
    void PrintWorld(char **world,int width,int hwight);

};