#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// 轮胎信息结构体
struct Tire {
    string model;
    string size;
};

// 底盘信息结构体
struct Chassis {
    string id;
    string model;
    string wheelbase;
    string track;
    string groundClearance;
    string turningRadius;
    string driveType;
    string maxRange;
    Tire tires[4];
};

// AGX套件结构体
struct AGXKit {
    string model;
    string aiPerformance;
    string cudaCores;
    string tensorCores;
    string memory;
    string storage;
};

// 双目摄像头结构体
struct StereoCamera {
    string model;
    string camera;
    string rgbResolution;
    string rgbFrameRate;
    string fov;
    string depthFrameRate;
};

// 激光雷达结构体
struct Lidar {
    string model;
    string channels;
    string range;
    string power;
};

// 陀螺仪结构体
struct Gyroscope {
    string model;
    string manufacturer;
};

// 显示屏结构体
struct Display {
    string size;
    string model;
};

// 电池模块结构体
struct Battery {
    string parameters;
    string output;
    string chargeTime;
};

// 智能小车结构体
struct SmartCar {
    string id;
    Chassis chassis;
    AGXKit agxKit;
    StereoCamera camera;
    Lidar lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
};

// 学生信息结构体
struct Student {
    string studentId;
    string name;
    string carId;
};

// 函数声明
void initializeCarWithDefaultValues(SmartCar& car);
void inputCarInfo(SmartCar& car, int carNumber);
void inputStudentInfo(Student& student, int studentNumber);
void assignCarsToStudents(vector<SmartCar>& cars, vector<Student>& students);
void saveDataToFiles(const vector<SmartCar>& cars, const vector<Student>& students);
bool loadDataFromFiles(vector<SmartCar>& cars, vector<Student>& students, map<string, Student>& carToStudentMap);
void displayCarInfo(const SmartCar& car, const Student* student, int index, int total);
void browseCars(const vector<SmartCar>& cars, const map<string, Student>& carToStudentMap);

int main() {
    const int NUM_CARS = 10;
    const int NUM_STUDENTS = 10;
    
    vector<SmartCar> cars(NUM_CARS);
    vector<Student> students(NUM_STUDENTS);
    
    cout << "=== 智能小车信息录入与分配系统 ===" << endl;
    
    // 录入10台小车信息
    cout << "\n开始录入" << NUM_CARS << "台智能小车信息：" << endl;
    for (int i = 0; i < NUM_CARS; i++) {
        cout << "\n--- 第" << (i + 1) << "台小车 ---" << endl;
        inputCarInfo(cars[i], i + 1);
    }
    
    // 录入10名学生信息
    cout << "\n开始录入" << NUM_STUDENTS << "名学生信息：" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "\n--- 第" << (i + 1) << "名学生 ---" << endl;
        inputStudentInfo(students[i], i + 1);
    }
    
    // 分配小车给学生
    assignCarsToStudents(cars, students);
    
    // 保存数据到文件
    saveDataToFiles(cars, students);
    
    cout << "\n=== 信息录入和分配完成！数据已保存到文件 ===" << endl;
    
    // 从文件加载数据并浏览
    cout << "\n从文件加载数据并开始浏览..." << endl;
    
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

// 使用默认值初始化小车信息
void initializeCarWithDefaultValues(SmartCar& car) {
    // 底盘默认值
    car.chassis.model = "SCOUT MINI";
    car.chassis.wheelbase = "451mm";
    car.chassis.track = "490mm";
    car.chassis.groundClearance = "115mm";
    car.chassis.turningRadius = "0m";
    car.chassis.driveType = "四轮四驱";
    car.chassis.maxRange = "10KM";
    
    // 轮胎默认值（固定为公路轮）
    for (int i = 0; i < 4; i++) {
        car.chassis.tires[i].model = "公路轮";
        car.chassis.tires[i].size = "175mm";
    }
    
    // AGX套件默认值
    car.agxKit.model = "AGX Xavier";
    car.agxKit.aiPerformance = "32 TOPS";
    car.agxKit.cudaCores = "512";
    car.agxKit.tensorCores = "64";
    car.agxKit.memory = "32G";
    car.agxKit.storage = "32G";
    
    // 双目摄像头默认值
    car.camera.model = "RealSense D435i";
    car.camera.camera = "D430";
    car.camera.rgbResolution = "1920*1080";
    car.camera.rgbFrameRate = "30";
    car.camera.fov = "87*58";
    car.camera.depthFrameRate = "90";
    
    // 激光雷达默认值
    car.lidar.model = "RS-Helios-16p";
    car.lidar.channels = "16";
    car.lidar.range = "100m";
    car.lidar.power = "8W";
    
    // 陀螺仪默认值
    car.gyro.model = "CH110";
    car.gyro.manufacturer = "NXP";
    
    // 显示屏默认值
    car.display.size = "11.6";
    car.display.model = "super";
    
    // 电池模块默认值
    car.battery.parameters = "24V/15Ah";
    car.battery.output = "24V";
    car.battery.chargeTime = "2H";
}

// 输入小车信息
void inputCarInfo(SmartCar& car, int carNumber) {
    // 初始化默认值
    initializeCarWithDefaultValues(car);
    
    // 输入小车编号
    cout << "请输入小车编号(cqusn开头的16位数字+字母): ";
    cin >> car.id;
    
    // 输入底盘编号
    cout << "请输入底盘编号(dp开头的8位数字+字母): ";
    cin >> car.chassis.id;
    
    cout << "第" << carNumber << "台小车信息录入完成！" << endl;
}

// 输入学生信息
void inputStudentInfo(Student& student, int studentNumber) {
    cout << "请输入学生学号: ";
    cin >> student.studentId;
    
    cout << "请输入学生姓名: ";
    cin >> student.name;
    
    cout << "第" << studentNumber << "名学生信息录入完成！" << endl;
}

// 分配小车给学生
void assignCarsToStudents(vector<SmartCar>& cars, vector<Student>& students) {
    cout << "\n开始分配小车给学生..." << endl;
    for (size_t i = 0; i < students.size(); i++) {
        if (i < cars.size()) {
            students[i].carId = cars[i].id;
            cout << "学生 " << students[i].name << "(" << students[i].studentId 
                 << ") 分配到小车: " << cars[i].id << endl;
        }
    }
}

// 保存数据到文件
void saveDataToFiles(const vector<SmartCar>& cars, const vector<Student>& students) {
    // 保存小车详细信息
    ofstream carFile("smart_cars_details.txt");
    if (carFile.is_open()) {
        carFile << "=== 智能小车详细信息 ===" << endl;
        for (size_t i = 0; i < cars.size(); i++) {
            carFile << "\n【第" << (i + 1) << "台小车】" << endl;
            carFile << "小车编号: " << cars[i].id << endl;
            
            carFile << "底盘信息:" << endl;
            carFile << "  编号: " << cars[i].chassis.id << endl;
            carFile << "  型号: " << cars[i].chassis.model << endl;
            carFile << "  轴距: " << cars[i].chassis.wheelbase << endl;
            carFile << "  轮距: " << cars[i].chassis.track << endl;
            carFile << "  最小离地间隙: " << cars[i].chassis.groundClearance << endl;
            carFile << "  最小转弯半径: " << cars[i].chassis.turningRadius << endl;
            carFile << "  驱动形式: " << cars[i].chassis.driveType << endl;
            carFile << "  最大行程: " << cars[i].chassis.maxRange << endl;
            carFile << "  轮胎信息:" << endl;
            carFile << "    型号: " << cars[i].chassis.tires[0].model << endl;
            carFile << "    尺寸: " << cars[i].chassis.tires[0].size << endl;
            
            carFile << "AGX套件:" << endl;
            carFile << "  型号: " << cars[i].agxKit.model << endl;
            carFile << "  AI性能: " << cars[i].agxKit.aiPerformance << endl;
            carFile << "  CUDA核心: " << cars[i].agxKit.cudaCores << endl;
            carFile << "  Tensor CORE: " << cars[i].agxKit.tensorCores << endl;
            carFile << "  显存: " << cars[i].agxKit.memory << endl;
            carFile << "  存储: " << cars[i].agxKit.storage << endl;
            
            carFile << "双目摄像头:" << endl;
            carFile << "  型号: " << cars[i].camera.model << endl;
            carFile << "  摄像头: " << cars[i].camera.camera << endl;
            carFile << "  RGB帧分辨率: " << cars[i].camera.rgbResolution << endl;
            carFile << "  RGB帧率: " << cars[i].camera.rgbFrameRate << endl;
            carFile << "  FOV: " << cars[i].camera.fov << endl;
            carFile << "  深度帧率: " << cars[i].camera.depthFrameRate << endl;
            
            carFile << "多线激光雷达:" << endl;
            carFile << "  型号: " << cars[i].lidar.model << endl;
            carFile << "  通道数: " << cars[i].lidar.channels << endl;
            carFile << "  测试范围: " << cars[i].lidar.range << endl;
            carFile << "  功耗: " << cars[i].lidar.power << endl;
            
            carFile << "9轴陀螺仪:" << endl;
            carFile << "  型号: " << cars[i].gyro.model << endl;
            carFile << "  厂家: " << cars[i].gyro.manufacturer << endl;
            
            carFile << "液晶显示屏:" << endl;
            carFile << "  尺寸: " << cars[i].display.size << endl;
            carFile << "  型号: " << cars[i].display.model << endl;
            
            carFile << "电池模块:" << endl;
            carFile << "  参数: " << cars[i].battery.parameters << endl;
            carFile << "  对外供电: " << cars[i].battery.output << endl;
            carFile << "  充电时长: " << cars[i].battery.chargeTime << endl;
            carFile << "----------------------------------------" << endl;
        }
        carFile.close();
    }
    
    // 保存分配信息
    ofstream assignFile("car_assignment.txt");
    if (assignFile.is_open()) {
        assignFile << "学号,姓名,小车编号" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            assignFile << students[i].studentId << "," 
                      << students[i].name << "," 
                      << students[i].carId << endl;
        }
        assignFile.close();
    }
    
    cout << "\n数据已保存到以下文件:" << endl;
    cout << "1. smart_cars_details.txt - 小车详细信息" << endl;
    cout << "2. car_assignment.txt - 分配信息表" << endl;
}

// 从文件加载数据
bool loadDataFromFiles(vector<SmartCar>& cars, vector<Student>& students, map<string, Student>& carToStudentMap) {
    // 加载小车信息
    ifstream carFile("smart_cars_details.txt");
    if (!carFile.is_open()) {
        cout << "无法打开小车信息文件！" << endl;
        return false;
    }
    
    string line;
    SmartCar currentCar;
    bool readingCar = false;
    
    while (getline(carFile, line)) {
        if (line.find("【第") != string::npos && line.find("台小车】") != string::npos) {
            if (readingCar) {
                cars.push_back(currentCar);
            }
            readingCar = true;
            initializeCarWithDefaultValues(currentCar);
        }
        else if (readingCar) {
            if (line.find("小车编号: ") != string::npos) {
                currentCar.id = line.substr(line.find(": ") + 2);
            }
            else if (line.find("底盘编号: ") != string::npos) {
                currentCar.chassis.id = line.substr(line.find(": ") + 2);
            }
        }
    }
    
    if (readingCar) {
        cars.push_back(currentCar);
    }
    
    carFile.close();
    
    // 加载学生分配信息
    ifstream assignFile("car_assignment.txt");
    if (!assignFile.is_open()) {
        cout << "无法打开分配信息文件！" << endl;
        return false;
    }
    
    // 跳过标题行
    getline(assignFile, line);
    
    while (getline(assignFile, line)) {
        if (line.empty()) continue;
        
        Student student;
        size_t pos1 = line.find(',');
        if (pos1 != string::npos) {
            student.studentId = line.substr(0, pos1);
            size_t pos2 = line.find(',', pos1 + 1);
            if (pos2 != string::npos) {
                student.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                student.carId = line.substr(pos2 + 1);
                students.push_back(student);
                carToStudentMap[student.carId] = student;
            }
        }
    }
    
    assignFile.close();
    
    cout << "成功加载 " << cars.size() << " 台小车信息和 " << students.size() << " 名学生信息" << endl;
    return true;
}

// 显示小车信息
void displayCarInfo(const SmartCar& car, const Student* student, int index, int total) {
    cout << "\n==========================================" << endl;
    cout << "=== 智能小车信息浏览 ===" << endl;
    cout << "当前显示: 第 " << index + 1 << " / " << total << " 台" << endl;
    cout << "==========================================" << endl;
    
    cout << "\n【分配信息】" << endl;
    if (student != nullptr) {
        cout << "学生姓名: " << student->name << endl;
        cout << "学生学号: " << student->studentId << endl;
        cout << "分配小车: " << car.id << endl;
    } else {
        cout << "未分配学生" << endl;
    }
    
    cout << "\n【小车基本信息】" << endl;
    cout << "小车编号: " << car.id << endl;
    
    cout << "\n【底盘信息】" << endl;
    cout << "底盘编号: " << car.chassis.id << endl;
    cout << "型号: " << car.chassis.model << endl;
    cout << "轴距: " << car.chassis.wheelbase << endl;
    cout << "轮距: " << car.chassis.track << endl;
    cout << "最小离地间隙: " << car.chassis.groundClearance << endl;
    cout << "最小转弯半径: " << car.chassis.turningRadius << endl;
    cout << "驱动形式: " << car.chassis.driveType << endl;
    cout << "最大行程: " << car.chassis.maxRange << endl;
    cout << "轮胎型号: " << car.chassis.tires[0].model << endl;
    cout << "轮胎尺寸: " << car.chassis.tires[0].size << endl;
    
    cout << "\n【AGX套件】" << endl;
    cout << "型号: " << car.agxKit.model << endl;
    cout << "AI性能: " << car.agxKit.aiPerformance << endl;
    cout << "CUDA核心: " << car.agxKit.cudaCores << endl;
    cout << "Tensor CORE: " << car.agxKit.tensorCores << endl;
    cout << "显存: " << car.agxKit.memory << endl;
    cout << "存储: " << car.agxKit.storage << endl;
    
    cout << "\n【双目摄像头】" << endl;
    cout << "型号: " << car.camera.model << endl;
    cout << "摄像头: " << car.camera.camera << endl;
    cout << "RGB帧分辨率: " << car.camera.rgbResolution << endl;
    cout << "RGB帧率: " << car.camera.rgbFrameRate << endl;
    cout << "FOV: " << car.camera.fov << endl;
    cout << "深度帧率: " << car.camera.depthFrameRate << endl;
    
    cout << "\n【多线激光雷达】" << endl;
    cout << "型号: " << car.lidar.model << endl;
    cout << "通道数: " << car.lidar.channels << endl;
    cout << "测试范围: " << car.lidar.range << endl;
    cout << "功耗: " << car.lidar.power << endl;
    
    cout << "\n【9轴陀螺仪】" << endl;
    cout << "型号: " << car.gyro.model << endl;
    cout << "厂家: " << car.gyro.manufacturer << endl;
    
    cout << "\n【液晶显示屏】" << endl;
    cout << "尺寸: " << car.display.size << endl;
    cout << "型号: " << car.display.model << endl;
    
    cout << "\n【电池模块】" << endl;
    cout << "参数: " << car.battery.parameters << endl;
    cout << "对外供电: " << car.battery.output << endl;
    cout << "充电时长: " << car.battery.chargeTime << endl;
    
    cout << "\n==========================================" << endl;
    cout << "操作提示: n - 下一辆, p - 上一辆, q - 退出" << endl;
    
    if (index == 0) {
        cout << "提示: 已是第一台,按p无效" << endl;
    }
    if (index == total - 1) {
        cout << "提示: 已是最后一台,按n无效" << endl;
    }
    cout << "请输入操作指令: ";
}

// 浏览小车信息
void browseCars(const vector<SmartCar>& cars, const map<string, Student>& carToStudentMap) {
    int currentIndex = 0;
    int total = cars.size();
    
    if (total == 0) {
        cout << "没有小车信息可浏览！" << endl;
        return;
    }
    
    while (true) {
        // 查找当前小车对应的学生信息
        const Student* student = nullptr;
        auto it = carToStudentMap.find(cars[currentIndex].id);
        if (it != carToStudentMap.end()) {
            student = &(it->second);
        }
        
        displayCarInfo(cars[currentIndex], student, currentIndex, total);
        
        string input;
        cin >> input;
        
        if (input == "n" || input == "N") {
            if (currentIndex < total - 1) {
                currentIndex++;
            } else {
                cout << "已经是最后一台小车，无法继续向下浏览！" << endl;
            }
        }
        else if (input == "p" || input == "P") {
            if (currentIndex > 0) {
                currentIndex--;
            } else {
                cout << "已经是第一台小车，无法继续向上浏览！" << endl;
            }
        }
        else if (input == "q" || input == "Q") {
            break;
        }
        else {
            cout << "无效指令，请使用 n(下一辆), p(上一辆) 或 q(退出)！" << endl;
        }
    }
    
    cout << "\n浏览结束,感谢使用！" << endl;
}