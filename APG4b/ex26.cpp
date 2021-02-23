#include <bits/stdc++.h>
using namespace std;
#define FOR_ITR(i, itr) for(int i = 0; i < (itr).size(); i++)
#define DEBUG_DONE(txt) cout << "debug : " << txt << endl
#define DEBUG_VAL(txt, n) cout << "debug : " << txt << " : " << n << endl
#define PRINT_ERROR(txt) cout << "##ERROR : " << txt << " ##" << endl
#define PRINT_ERROR_VAL(txt, val) \
cout << "##ERROR : " << txt << " : VALUE : " << val << " ##" << endl

// split space strings.
vector<string> split_input(int line_number) {
    vector<string> result;
    string s;
    int count = 0;

    while(count < line_number && cin >> s) {
        result.push_back(s);
        if(s == ";") {
            count++;
//            DEBUG_VAL("count", count);
        }
//        DEBUG_VAL("s", s);
    }
    return result;
}

// print vector with template
template <class T> void print_vec(vector<T> vec) {
    FOR_ITR(prop, vec) {
        cout << vec.at(prop) << endl;
    }
}

struct calculator {
    map<string, int> m_variable_scalar;
    map<string, vector<int>> m_variable_vector;
    // flags.
    // [in [] or not, minud or plus, print or not, scalar or vecotr].
    bitset<4> m_status;
    int m_vec_index = 0;
    string m_assign_key;

    calculator() {
        // print key initialize.
        m_variable_scalar["print"] = 0;
        m_variable_vector["print"] = {};
    }

    // status flag control functions.
    bool is_vec_line() {
        return m_status.test(0);
    }
    bool is_scalar_line() {
        return !(m_status.test(0));
    }
    bool is_print() {
        return m_status.test(1);
    }
    bool is_minus() {
        return m_status.test(2);
    }
    bool is_in_vec() {
        return m_status.test(3);
    }
    void set_vec_line() {
        m_status.set(0);
    }
    void set_print() {
        m_status.set(1);
        set_assign_key("print");
    }
    void set_plus() {
        m_status.reset(2);
    }
    void set_minus() {
        m_status.set(2);
    }
    void set_in_vec() {
        m_status.set(3);
    }
    void reset_in_vec() {
        m_status.reset(3);
    }
    void reset_status() {
        m_status.reset();
    }
    void set_status(string str) {
        if(str == "print_vec") {
            set_vec_line();
            set_print();
        } else if(str == "print_int") {
//            DEBUG_DONE("set_status() : in print_int");
            set_print();
        } else if(str == "vec") {
            set_vec_line();
        } else if(str == "int") {
            // not work.
        } else {
            PRINT_ERROR_VAL("set_status. this value does not exist.", str);
        }
//        DEBUG_VAL("set_status() : assign_key", get_assign_key());
    }

    // print variable control.
    void reset_print() {
        m_variable_scalar.at("print") = 0;
        m_variable_vector.at("print") = {};
    }

    // vec_index control functions.
    int get_vec_index() {
        return m_vec_index;
    }
    // return before add value.
    int add_vec_index() {
        return m_vec_index++;
    }
    void reset_vec_index() {
        m_vec_index = 0;
    }

    // initialize each line roop.
    void init_line(string str) {
        set_status(str);
        reset_vec_index();
    }

    // assign_key control functions.
    string get_assign_key() {
        /*
        if(is_empty_assign_key()) {
            DEBUG_DONE("get_assign_key() : assign_key is empty.");
        }
        */
        return m_assign_key;
    }
    void set_assign_key(string str) {
        if(is_empty_assign_key()) {
//            DEBUG_VAL("set_assign_key() : assign_key", get_assign_key());
//            DEBUG_VAL("set_assign_key() : str", str);
            m_assign_key = str;
        }
    }
    bool is_empty_assign_key() {
        return m_assign_key.empty();
    }
    void reset_assign_key() {
        m_assign_key.clear();
    }

    // variable scalar
    bool has_scalar(string key) {
        return m_variable_scalar.count(key);
    }
    int get_scalar(string key) {
        if(!has_scalar(key)) {
            PRINT_ERROR_VAL("get_scalar() : does not exist key.", key);
        }
        return m_variable_scalar.at(key);
    }
    void set_scalar(string key, int num) {
        m_variable_scalar[key] = num; 
    }
    void add_scalar(string key, int num) {
        if(!(has_scalar(key))) {
            PRINT_ERROR_VAL("add_scalar : does not have key.", key);
        }
        if(is_minus()) {
            m_variable_scalar.at(key) -= num;
        } else {
            m_variable_scalar.at(key) += num;
        } 
    }

    // vector control.
    bool has_vec_key(string key) {
        return m_variable_vector.count(key);
    }
    bool has_vec_exist_val(string key) {
        return m_variable_vector.at(key).size() > get_vec_index();
    }
    vector<int> get_vec(string key) {
        if(!has_vec_key(key)) {
            PRINT_ERROR_VAL("get_vec() : does not exist key.", key);
        }
        return m_variable_vector.at(key);
    }
    void def_vec(string key) {
        m_variable_vector[key] = {};
    }
    void add_vec(string key, int num) {
//        DEBUG_VAL("add_vec() : has_vec_exist_val", has_vec_exist_val(get_assign_key()));
        if(has_vec_exist_val(get_assign_key())) {
            if(is_minus()) {
                m_variable_vector.at(key).at(add_vec_index()) -= num;
            } else {
                m_variable_vector.at(key).at(add_vec_index()) += num;
            }
        } else {
            m_variable_vector.at(key).push_back(num);
            add_vec_index();
        }
    }
    

    // math funcrions.
    void add(int num) {
//        DEBUG_VAL("add() : assign_key", get_assign_key());
//        DEBUG_VAL("add() : num", num);
        if(is_scalar_line()) {
            if(has_scalar(get_assign_key())) {
                add_scalar(get_assign_key(), num);
            } else {
//                DEBUG_VAL("add() : in not has scalar", num);
                set_scalar(get_assign_key(), num);
            }
//            DEBUG_VAL("add() : get scalar", get_scalar(get_assign_key()));
        } else if(is_vec_line()) {
//            DEBUG_DONE("in add.");
            if(!has_vec_key(get_assign_key())) {
//                DEBUG_DONE("in not has vec key in add.");
                def_vec(get_assign_key());
            }
            add_vec(get_assign_key(), num);
        } else {
            PRINT_ERROR("neither is_scalar_line nor is_vec_line");
        }
    }

    // print function.
    void print() {
//        DEBUG_VAL("print() : assign_key", get_assign_key());
        if(is_print()) {
            if(is_scalar_line()) {
                cout << get_scalar(get_assign_key()) << endl;
            } else {
                cout << "[ ";
                FOR_ITR(prop, get_vec(get_assign_key())) {
                    cout << get_vec(get_assign_key()).at(prop) << " ";
                }
                cout << "]" << endl;
            }
        }
    }
};

bool judge_number(string s) {
    return (s.compare("0") >= 0 && s.compare("9") <= 0);
}
bool judge_alphabet(string s) {
    return s.compare("a") >= 0 && s.compare("z") <= 0;
}

int main() {
    int line_number;
    cin >> line_number;
    vector<string> inputs = split_input(line_number);
//    PRINT_VEC(inputs);
    calculator calc;
    FOR_ITR(prop, inputs) {
//        DEBUG_VAL("start line.", inputs.at(prop));
        if(inputs.at(prop).size() > 1) {
            calc.init_line(inputs.at(prop));
//            DEBUG_VAL("status", calc.m_status);
        } else {
            if(inputs.at(prop) == ";") {
                calc.print();
                calc.reset_status();
                calc.reset_assign_key();
                calc.reset_print();
            } else if(inputs.at(prop) == "[") {
                calc.set_in_vec();
            } else if(inputs.at(prop) == "]") {
                calc.reset_in_vec();
                calc.reset_vec_index();
            } else if(inputs.at(prop) == "+") {
                calc.set_plus();
            } else if(inputs.at(prop) == "-") {
                calc.set_minus();
            } else if(judge_number(inputs.at(prop))) {
                int num = stoi(inputs.at(prop));
                calc.add(num);
            } else if(judge_alphabet(inputs.at(prop))) {
                if(calc.is_empty_assign_key()) {
                    calc.set_assign_key(inputs.at(prop));
                } else {
                    if(calc.is_scalar_line() || calc.is_in_vec()) {
                        calc.add(calc.get_scalar(inputs.at(prop)));
                    } else {
                        FOR_ITR(index, calc.get_vec(inputs.at(prop))) {
                            calc.add(calc.get_vec(inputs.at(prop)).at(index));
                        }
                        calc.reset_vec_index();
                    }
                }
                
            }
        }
//        DEBUG_VAL("assign key", calc.get_assign_key());
    }
}