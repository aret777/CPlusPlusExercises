#ifndef DESIGN_HPP
#define DESIGN_HPP

#include <iostream>
#include <vector>
#include <regex>
//Chain of responsibility

class StringValidator {
public:
    virtual ~StringValidator() {

    };
    virtual StringValidator *setNext(StringValidator *nextValidator) = 0;
    virtual std::string validate(std::string) = 0;
};

class BaseValidator: public StringValidator {
protected:
    StringValidator *next = nullptr;
public:
    virtual ~BaseValidator() {
        delete next;
    };
    StringValidator *setNext(StringValidator *nextValidator) override {
        next = nextValidator;
        return nextValidator;
    }
    virtual std::string validate(std::string testString) override {
        if (this->next) {
            return this->next->validate(testString);
        }
        return "Success!";
    }
};

class NotEmptyValidator: public BaseValidator {
public:
    std::string validate(std::string testString) override {
        std::cout << "Checking if empty...\n";
        
        if (testString.empty()) {
            return "Please enter a value";
        }
        
        return BaseValidator::validate(testString);
    }
};

class LengthValidator: public BaseValidator {
    int minLength;
public:
    LengthValidator(int minLength) : minLength(minLength) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if length equals" << minLength << "...\n";
        
        if (testString.length() < minLength) {
            return "Please enter a value longer than " + std::to_string(minLength);
        }
        
        return BaseValidator::validate(testString);
    }
};

class RegexValidator: public BaseValidator {
    std::string patternName;
    std::string regexString;
public:
    RegexValidator(std::string patternName, std::string regexString)
    : patternName(patternName), regexString(regexString) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if string is a valid " << patternName << "...\n";
        
        if (!std::regex_match(testString, std::regex(regexString))) {
            return "The value entered is not a valid " + patternName;
        }
        
        return BaseValidator::validate(testString);
    }
};

bool in_vector(const std::string &value, const std::vector<std::string> &v) {
    return std::find(v.begin(), v.end(), value) != v.end();
}

class HistoryValidator: public BaseValidator {
    std::vector<std::string> historyItems;
public:
    HistoryValidator(std::vector<std::string> historyItems) : historyItems(historyItems) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if string is in history...\n";
        
        if (in_vector(testString, historyItems)) {
            return "Please enter a value that you haven't entered before";
        }
        
        return BaseValidator::validate(testString);
    }
};

void ChainOfResponsibility(){
    std::vector<std::string> oldPasswords = { "abc123", "123456", "hello" };
    
    BaseValidator *emailValidator = new BaseValidator;
    
    emailValidator
        ->setNext(new NotEmptyValidator)
        ->setNext(new RegexValidator("email address", "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));
    
        std::cout << "Checking Emails ---------------\n";
        std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
        std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
        std::cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n\n";
    
    delete emailValidator;
}

//---------------------------------------------------------------------------------
// Observer pattern.

class Subscriber {
public:
    virtual void notify(const std::string & publisherName, const std::string & message) = 0;
    virtual std::string getName() = 0;
};

class Publisher {
public:
    virtual void subscribe(Subscriber *subscriber) = 0;
    virtual void unsubscribe(Subscriber *subscriber) = 0;
    virtual void publish(const std::string & message) = 0;
};

class ChatGroup : public Publisher {
    std::string groupName;
    std::vector<Subscriber*> subscribers;
public:
    ChatGroup(const std::string & name) : groupName(name) {};
    void subscribe(Subscriber *subscriber) override {
        this->subscribers.push_back(subscriber);
    };
    void unsubscribe(Subscriber *subscriber) override {
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(), [subscriber](Subscriber *s) { return s->getName() == subscriber->getName(); }), subscribers.end());
    };
    void publish(const std::string & message) override {
        for (auto subscriber : subscribers) {
            subscriber->notify(groupName, message);
        }
    };
};

class ChatUser : public Subscriber {
    std::string userName;
public:
    ChatUser(const std::string & userName) : userName(userName) {};
    void notify(const std::string & publisherName, const std::string & message) override {
        std::cout << userName << " received a new message from " << publisherName << ": " << message << "\n";
    }
    std::string getName() override { return userName; };
};

//---------------------------------------------------------------------------------
// Interpreter pattern.

class Expression {
public:
    virtual int evaluate() = 0;
};

// 5 + (10 + 1)
class OperationExpression : public Expression {
    std::string operatorSymbol;
    Expression *leftHandSide;
    Expression *rightHandSide;
public:
    OperationExpression(const std::string & operatorSymbol, Expression *lhs, Expression *rhs) : operatorSymbol(operatorSymbol), leftHandSide(lhs), rightHandSide(rhs) {};
    int evaluate() override {
        if (operatorSymbol == "plus") {
            return leftHandSide->evaluate() + rightHandSide->evaluate();
        } else if (operatorSymbol == "minus") {
            return leftHandSide->evaluate() - rightHandSide->evaluate();
        } else {
            std::cout << "Unrecognized operator: " << operatorSymbol;
            return 0;
        }
    }
};

class NumberExpression : public Expression {
    std::string numberString;
public:
    NumberExpression(const std::string & numberString) : numberString(numberString) {};
    int evaluate() override {
        return std::stoi(numberString);
    }
};

//---------------------------------------------------------------------------------
// State pattern.

class State {
public:
    virtual std::string getDescription() = 0;
    virtual State *getNextState() = 0;
};

class PurchasedState : public State {
    State *nextState = nullptr;
public:
    PurchasedState(State *nextState) : nextState(nextState) {};
    std::string getDescription() override {
        return "Current State: PURCHASED - Will be shipping soon\n";
    }
    State *getNextState() override { return nextState; };
};

class InTransitState : public State {
    State *nextState = nullptr;
public:
    InTransitState(State *nextState) : nextState(nextState) {};
    std::string getDescription() override {
        return "Current State: IN_TRANSIT - Your item is on the way\n";
    }
    State *getNextState() override { return nextState; };
};

class DeliveredState : public State {
    State *nextState = nullptr;
public:
    DeliveredState(State *nextState) : nextState(nextState) {};
    std::string getDescription() override {
        return "Current State: DELIVERED - Your item has arrived\n";
    }
    State *getNextState() override { return nextState; };
};

class Purchase {
    std::string productName;
    State *currentState;
public:
    Purchase(const std::string & productName, State *initialState)
        : productName(productName), currentState(initialState) {};
    std::string getDescription() {
        return currentState->getDescription();
    }
    void goToNextState() {
        if (currentState->getNextState()) {
            currentState = currentState->getNextState();
        } else {
            std::cout << "No more states!";
        }
    };
};

//---------------------------------------------------------------------------------
// Template method pattern.

class GreetingCardTemplate {
protected:
    virtual std::string intro(const std::string & to) {
        return "Dear " + to + ",\n";
    }
    virtual std::string occasion() {
        return "Just writing to say hi! Hope all is well with you.\n";
    }
    virtual std::string closing(const std::string & from) {
        return "Sincerely,\n" + from + "\n";
    }
public:
    std::string generate(const std::string & to, const std::string & from) {
        return intro(to) + occasion() + closing(from);
    }
};

class BirthdayCardTemplate : public GreetingCardTemplate {
protected:
    std::string occasion() override {
        return "Happy birthday!! Hope you have a wonderful day and lots of cake.\n";
    }
};

class NewYearsCardTemplate : public GreetingCardTemplate {
protected:
    std::string intro(const std::string & to) override {
        return to + "!!!\n";
    }
    std::string occasion() override {
        return "Happy New Years!!!! See you at the gym tomorrow!\n";
    }
};

//---------------------------------------------------------------------------------
// Memento pattern.
class Canvas;

class CanvasMemento {
    friend class Canvas;
    const std::vector<std::string> shapes;
public:
    CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
};

class Canvas {
    std::vector<std::string> shapes;
    std::vector<CanvasMemento*> oldStates;
public:
    ~Canvas() {
        for (auto p : oldStates) {
            delete p;
        }
        oldStates.clear();
    }
    void addShape(const std::string & newShape) {
        oldStates.push_back(new CanvasMemento(shapes));
        shapes.push_back(newShape);
    };
    void undo() {
        CanvasMemento *previousState = oldStates.back();
        oldStates.pop_back();
        shapes = previousState->shapes;
        delete previousState;
    }
    void clearAll() {
        shapes.clear();
    };
    std::vector<std::string> getShapes() { return shapes; };
};

//---------------------------------------------------------------------------------
// Singleton pattern.
class Leader
{
private:
	static Leader * _instance;
	Leader()
	{
		cout << "New leader elected" << endl;
	}
public:
	static Leader * getInstance()
	{
		if (_instance == NULL)
		{
			_instance = new Leader;
		}
		return _instance;
	}
	void giveSpeech()
	{
		cout << "Address the public" << endl;

	}
};

Leader* Leader::_instance = NULL;


#endif // DESIGN_HPP