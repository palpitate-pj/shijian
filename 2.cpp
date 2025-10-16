#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// 轮胎类
class Tire {
private:
    string model, size;
public:
    Tire(string m = "公路轮", string s = "175mm") : model(m), size(s) {}
    void setModel(string m) { model = m; }
    void setSize(string s) { size = s; }
    void print() const { cout << "    型号: " << model << "\n    尺寸: " << size << endl; }
    void save(ofstream &file) const { file << "    型号: " << model << "\n    尺寸: " << size << endl; }
};

// AGX套件类
class AGXKit {
private:
    string model, aiPerformance, cudaCores, tensorCores, memory, storage;
public:
    AGXKit(string m = "AGX Xavier", string ai = "32 TOPS", string cuda = "512", 
           string tensor = "64", string mem = "32G", string store = "32G") 
        : model(m), aiPerformance(ai), cudaCores(cuda), tensorCores(tensor), memory(mem), storage(store) {}
    void setModel(string m) { model = m; }
    void setAiPerformance(string ai) { aiPerformance = ai; }
    void setCudaCores(string cuda) { cudaCores = cuda; }
    void setTensorCores(string tensor) { tensorCores = tensor; }
    void setMemory(string mem) { memory = mem; }
    void setStorage(string store) { storage = store; }
    void print() const {
        cout << "  型号: " << model << "\n  AI性能: " << aiPerformance 
             << "\n  CUDA核心: " << cudaCores << "\n  Tensor CORE: " << tensorCores
             << "\n  显存: " << memory << "\n  存储: " << storage << endl;
    }
    void save(ofstream &file) const {
        file << "  型号: " << model << "\n  AI性能: " << aiPerformance 
             << "\n  CUDA核心: " << cudaCores << "\n  Tensor CORE: " << tensorCores
             << "\n  显存: " << memory << "\n  存储: " << storage << endl;
    }
};

// 双目摄像头类
class StereoCamera {
private:
    string model, camera, rgbResolution, rgbFrameRate, fov, depthFrameRate;
public:
    StereoCamera(string m = "RealSense D435i", string cam = "D430", string res = "1920*1080",
                 string rate = "30", string f = "87*58", string depth = "90")
        : model(m), camera(cam), rgbResolution(res), rgbFrameRate(rate), fov(f), depthFrameRate(depth) {}
    void setModel(string m) { model = m; }
    void setCamera(string cam) { camera = cam; }
    void setRgbResolution(string res) { rgbResolution = res; }
    void setRgbFrameRate(string rate) { rgbFrameRate = rate; }
    void setFov(string f) { fov = f; }
    void setDepthFrameRate(string depth) { depthFrameRate = depth; }
    void print() const {
        cout << "  型号: " << model << "\n  摄像头: " << camera << "\n  RGB帧分辨率: " << rgbResolution
             << "\n  RGB帧率: " << rgbFrameRate << "\n  FOV: " << fov << "\n  深度帧率: " << depthFrameRate << endl;
    }
    void save(ofstream &file) const {
        file << "  型号: " << model << "\n  摄像头: " << camera << "\n  RGB帧分辨率: " << rgbResolution
             << "\n  RGB帧率: " << rgbFrameRate << "\n  FOV: " << fov << "\n  深度帧率: " << depthFrameRate << endl;
    }
};

// 多线激光雷达类
class Lidar {
private:
    string model, channels, range, power;
public:
    Lidar(string m = "RS-Helios-16p", string ch = "16", string r = "100m", string p = "8W")
        : model(m), channels(ch), range(r), power(p) {}
    void setModel(string m) { model = m; }
    void setChannels(string ch) { channels = ch; }
    void setRange(string r) { range = r; }
    void setPower(string p) { power = p; }
    void print() const {
        cout << "  型号: " << model << "\n  通道数: " << channels 
             << "\n  测试范围: " << range << "\n  功耗: " << power << endl;
    }
    void save(ofstream &file) const {
        file << "  型号: " << model << "\n  通道数: " << channels 
             << "\n  测试范围: " << range << "\n  功耗: " << power << endl;
    }
};

// 9轴陀螺仪类
class Gyroscope {
private:
    string model, manufacturer;
public:
    Gyroscope(string m = "CH110", string manu = "NXP") : model(m), manufacturer(manu) {}
    void setModel(string m) { model = m; }
    void setManufacturer(string manu) { manufacturer = manu; }
    void print() const { cout << "  型号: " << model << "\n  厂家: " << manufacturer << endl; }
    void save(ofstream &file) const { file << "  型号: " << model << "\n  厂家: " << manufacturer << endl; }
};

// 液晶显示屏类
class Display {
private:
    string size, model;
public:
    Display(string s = "11.6", string m = "super") : size(s), model(m) {}
    void setSize(string s) { size = s; }
    void setModel(string m) { model = m; }
    void print() const { cout << "  尺寸: " << size << "\n  型号: " << model << endl; }
    void save(ofstream &file) const { file << "  尺寸: " << size << "\n  型号: " << model << endl; }
};

// 电池模块类
class Battery {
private:
    string parameters, output, chargeTime;
public:
    Battery(string param = "24V/15Ah", string out = "24V", string charge = "2H")
        : parameters(param), output(out), chargeTime(charge) {}
    void setParameters(string param) { parameters = param; }
    void setOutput(string out) { output = out; }
    void setChargeTime(string charge) { chargeTime = charge; }
    void print() const {
        cout << "  参数: " << parameters << "\n  对外供电: " << output 
             << "\n  充电时长: " << chargeTime << endl;
    }
    void save(ofstream &file) const {
        file << "  参数: " << parameters << "\n  对外供电: " << output 
             << "\n  充电时长: " << chargeTime << endl;
    }
};

// 底盘类
class Chassis {
private:
    string id, model, wheelbase, track, groundClearance, turningRadius, driveType, maxRange;
    Tire tires[4];
public:
    Chassis(string i = "", string m = "SCOUT MINI", string wb = "451mm", string t = "490mm",
            string gc = "115mm", string tr = "0m", string dt = "四轮四驱", string mr = "10KM")
        : id(i), model(m), wheelbase(wb), track(t), groundClearance(gc), turningRadius(tr), driveType(dt), maxRange(mr) {}
    void setId(string i) { id = i; }
    void setModel(string m) { model = m; }
    void setWheelbase(string wb) { wheelbase = wb; }
    void setTrack(string t) { track = t; }
    void setGroundClearance(string gc) { groundClearance = gc; }
    void setTurningRadius(string tr) { turningRadius = tr; }
    void setDriveType(string dt) { driveType = dt; }
    void setMaxRange(string mr) { maxRange = mr; }
    void setTire(int index, const Tire &tire) { if (index >= 0 && index < 4) tires[index] = tire; }
    void print() const {
        cout << "  编号: " << id << "\n  型号: " << model << "\n  轴距: " << wheelbase
             << "\n  轮距: " << track << "\n  最小离地间隙: " << groundClearance
             << "\n  最小转弯半径: " << turningRadius << "\n  驱动形式: " << driveType
             << "\n  最大行程: " << maxRange << "\n  轮胎信息:" << endl;
        tires[0].print();
    }
    void save(ofstream &file) const {
        file << "  编号: " << id << "\n  型号: " << model << "\n  轴距: " << wheelbase
             << "\n  轮距: " << track << "\n  最小离地间隙: " << groundClearance
             << "\n  最小转弯半径: " << turningRadius << "\n  驱动形式: " << driveType
             << "\n  最大行程: " << maxRange << "\n  轮胎信息:" << endl;
        tires[0].save(file);
    }
};

// 学生类
class Student {
private:
    string studentId, name, carId;
public:
    Student(string id = "", string n = "", string cid = "") : studentId(id), name(n), carId(cid) {}
    void setStudentId(string id) { studentId = id; }
    void setName(string n) { name = n; }
    void setCarId(string cid) { carId = cid; }
    string getStudentId() const { return studentId; }
    string getName() const { return name; }
    string getCarId() const { return carId; }
    void print() const {
        cout << "学生姓名: " << name << "\n学生学号: " << studentId;
        if (!carId.empty()) cout << "\n分配小车: " << carId;
        cout << endl;
    }
    void save(ofstream &file) const { file << studentId << "," << name << "," << carId << endl; }
};

// 智能小车类
class SmartCar {
private:
    string id;
    Chassis chassis;
    AGXKit agxKit;
    StereoCamera camera;
    Lidar lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
public:
    SmartCar(string carId = "") : id(carId) {}
    void setId(string carId) { id = carId; }
    void setChassis(const Chassis &ch) { chassis = ch; }
    void setAgxKit(const AGXKit &kit) { agxKit = kit; }
    void setCamera(const StereoCamera &cam) { camera = cam; }
    void setLidar(const Lidar &lid) { lidar = lid; }
    void setGyro(const Gyroscope &g) { gyro = g; }
    void setDisplay(const Display &disp) { display = disp; }
    void setBattery(const Battery &bat) { battery = bat; }
    string getId() const { return id; }
    void print() const {
        cout << "小车编号: " << id << "\n底盘信息:" << endl; chassis.print();
        cout << "AGX套件:" << endl; agxKit.print();
        cout << "双目摄像头:" << endl; camera.print();
        cout << "多线激光雷达:" << endl; lidar.print();
        cout << "9轴陀螺仪:" << endl; gyro.print();
        cout << "液晶显示屏:" << endl; display.print();
        cout << "电池模块:" << endl; battery.print();
    }
    void save(ofstream &file) const {
        file << "小车编号: " << id << "\n底盘信息:" << endl; chassis.save(file);
        file << "AGX套件:" << endl; agxKit.save(file);
        file << "双目摄像头:" << endl; camera.save(file);
        file << "多线激光雷达:" << endl; lidar.save(file);
        file << "9轴陀螺仪:" << endl; gyro.save(file);
        file << "液晶显示屏:" << endl; display.save(file);
        file << "电池模块:" << endl; battery.save(file);
        file << "----------------------------------------" << endl;
    }
};

// 函数声明
void inputCarInfo(SmartCar& car, int carNumber);
void inputStudentInfo(Student& student, int studentNumber);
void assignCarsToStudents(vector<SmartCar>& cars, vector<Student>& students);
void saveDataToFiles(const vector<SmartCar>& cars, const vector<Student>& students);
bool loadDataFromFiles(vector<SmartCar>& cars, vector<Student>& students, map<string, Student>& carToStudentMap);
void displayCarInfo(const SmartCar& car, const Student* student, int index, int total);
void browseCars(const vector<SmartCar>& cars, const map<string, Student>& carToStudentMap);

int main() {
    vector<SmartCar> cars(10);
    vector<Student> students(10);
    
    cout << "=== 智能小车信息录入与分配系统 ===\n" << endl;
    
    // 录入信息
    cout << "开始录入10台智能小车信息：" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\n--- 第" << (i + 1) << "台小车 ---" << endl;
        inputCarInfo(cars[i], i + 1);
    }
    
    cout << "\n开始录入10名学生信息：" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\n--- 第" << (i + 1) << "名学生 ---" << endl;
        inputStudentInfo(students[i], i + 1);
    }
    
    // 分配并保存
    assignCarsToStudents(cars, students);
    saveDataToFiles(cars, students);
    
    cout << "\n=== 信息录入和分配完成！数据已保存到文件 ===\n" << endl;
    
    // 从文件加载并浏览
    cout << "从文件加载数据并开始浏览..." << endl;
    vector<SmartCar> loadedCars;
    vector<Student> loadedStudents;
    map<string, Student> carToStudentMap;
    
    if (loadDataFromFiles(loadedCars, loadedStudents, carToStudentMap)) {
        browseCars(loadedCars, carToStudentMap);
    } else {
        cout << "文件加载失败，无法浏览数据。" << endl;
    }
    
    return 0;
}

void inputCarInfo(SmartCar& car, int carNumber) {
    string carId, chassisId;
    cout << "请输入小车编号(cqusn开头的16位数字+字母): ";
    cin >> carId;
    car.setId(carId);
    
    cout << "请输入底盘编号(dp开头的8位数字+字母): ";
    cin >> chassisId;
    
    Chassis chassis;
    chassis.setId(chassisId);
    
    // 设置轮胎
    Tire tire;
    int tireChoice;
    cout << "请选择轮胎型号 (1-公路轮, 2-麦克纳姆轮): ";
    cin >> tireChoice;
    tire.setModel(tireChoice == 1 ? "公路轮" : "麦克纳姆轮");
    for (int i = 0; i < 4; i++) chassis.setTire(i, tire);
    
    car.setChassis(chassis);
    cout << "第" << carNumber << "台小车信息录入完成！" << endl;
}

void inputStudentInfo(Student& student, int studentNumber) {
    string studentId, name;
    cout << "请输入学生学号: ";
    cin >> studentId;
    cout << "请输入学生姓名: ";
    cin >> name;
    student.setStudentId(studentId);
    student.setName(name);
    cout << "第" << studentNumber << "名学生信息录入完成！" << endl;
}

void assignCarsToStudents(vector<SmartCar>& cars, vector<Student>& students) {
    cout << "\n开始分配小车给学生..." << endl;
    for (size_t i = 0; i < students.size() && i < cars.size(); i++) {
        students[i].setCarId(cars[i].getId());
        cout << "学生 " << students[i].getName() << "(" << students[i].getStudentId() 
             << ") 分配到小车: " << cars[i].getId() << endl;
    }
}

void saveDataToFiles(const vector<SmartCar>& cars, const vector<Student>& students) {
    ofstream carFile("smart_cars_details.txt");
    if (carFile.is_open()) {
        carFile << "=== 智能小车详细信息 ===" << endl;
        for (size_t i = 0; i < cars.size(); i++) {
            carFile << "\n【第" << (i + 1) << "台小车】" << endl;
            cars[i].save(carFile);
        }
        carFile.close();
    }
    
    ofstream assignFile("car_assignment.txt");
    if (assignFile.is_open()) {
        assignFile << "学号,姓名,小车编号" << endl;
        for (const auto& student : students) student.save(assignFile);
        assignFile.close();
    }
    
    cout << "数据已保存到: smart_cars_details.txt 和 car_assignment.txt" << endl;
}

bool loadDataFromFiles(vector<SmartCar>& cars, vector<Student>& students, map<string, Student>& carToStudentMap) {
    // 加载分配信息
    ifstream assignFile("car_assignment.txt");
    if (!assignFile.is_open()) return false;
    
    string line;
    getline(assignFile, line); // 跳过标题行
    
    while (getline(assignFile, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find(','), pos2 = line.find(',', pos1 + 1);
        if (pos1 != string::npos && pos2 != string::npos) {
            Student student(line.substr(0, pos1), line.substr(pos1 + 1, pos2 - pos1 - 1), line.substr(pos2 + 1));
            students.push_back(student);
            carToStudentMap[student.getCarId()] = student;
        }
    }
    assignFile.close();
    
    // 加载小车信息
    ifstream carFile("smart_cars_details.txt");
    if (!carFile.is_open()) return false;
    
    while (getline(carFile, line)) {
        if (line.find("小车编号: ") != string::npos) {
            cars.push_back(SmartCar(line.substr(line.find(": ") + 2)));
        }
    }
    carFile.close();
    
    cout << "成功加载 " << cars.size() << " 台小车信息和 " << students.size() << " 名学生信息" << endl;
    return true;
}

void displayCarInfo(const SmartCar& car, const Student* student, int index, int total) {
    cout << "\n==========================================" << endl;
    cout << "=== 智能小车信息浏览 ===" << endl;
    cout << "当前显示: 第 " << index + 1 << " / " << total << " 台" << endl;
    cout << "==========================================" << endl;
    
    cout << "\n【分配信息】" << endl;
    if (student) student->print();
    else cout << "未分配学生" << endl;
    
    cout << "\n【小车基本信息】" << endl;
    car.print();
    
    cout << "\n==========================================" << endl;
    cout << "操作提示: n-下一辆, p-上一辆, q-退出" << endl;
    if (index == 0) cout << "提示: 已是第一台，按p无效" << endl;
    if (index == total - 1) cout << "提示: 已是最后一台，按n无效" << endl;
    cout << "请输入操作指令: ";
}

void browseCars(const vector<SmartCar>& cars, const map<string, Student>& carToStudentMap) {
    int currentIndex = 0, total = cars.size();
    if (total == 0) {
        cout << "没有小车信息可浏览！" << endl;
        return;
    }
    
    while (true) {
        const Student* student = nullptr;
        auto it = carToStudentMap.find(cars[currentIndex].getId());
        if (it != carToStudentMap.end()) student = &(it->second);
        
        displayCarInfo(cars[currentIndex], student, currentIndex, total);
        
        string input;
        cin >> input;
        
        if ((input == "n" || input == "N") && currentIndex < total - 1) currentIndex++;
        else if ((input == "p" || input == "P") && currentIndex > 0) currentIndex--;
        else if (input == "q" || input == "Q") break;
        else cout << "无效指令，请使用 n/p/q！" << endl;
    }
    
    cout << "\n浏览结束，感谢使用！" << endl;
}