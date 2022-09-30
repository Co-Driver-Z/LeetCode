// 1、双队列管理
class AnimalShelf {
public:
    AnimalShelf() {
    }
    void enqueue(vector<int> animal) {
        if (animal.at(1) == 0)
            this->Cat.push(animal);
        else
            this->Dog.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> Result;
        if (this->Cat.empty() && this->Dog.empty()){
            Result = {-1, -1};
            return Result;
        } 
        else if (!this->Cat.empty() && this->Dog.empty()){
            Result = this->Cat.front();
            this->Cat.pop();
            return Result;
        }
        else if (this->Cat.empty() && !this->Dog.empty()){
            Result = this->Dog.front();
            this->Dog.pop();
            return Result;
        }
        else{
            int CatNum = this->Cat.front().at(0);
            int DogNum = this->Dog.front().at(0);
            if (CatNum <= DogNum){
                Result = this->Cat.front();
                this->Cat.pop();
            }
            else {
                Result = this->Dog.front();
                this->Dog.pop();
            }
            return Result;
        }
    }
    
    vector<int> dequeueDog() {
        vector<int> Result;
        if (this->Dog.empty()){
            Result = {-1, -1};
            return Result;
        }
        Result = this->Dog.front();
        this->Dog.pop();
        return Result; 
    }
    
    vector<int> dequeueCat() {
        vector<int> Result;
        if (this->Cat.empty()){
            Result = {-1, -1};
            return Result;
        }
        Result = this->Cat.front();
        this->Cat.pop();
        return Result;
    }
private:
    queue<vector<int>> Cat;   // 猫队列
    queue<vector<int>> Dog;   // 狗队列
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */