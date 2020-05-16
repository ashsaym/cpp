
#include <iostream>
#include <iomanip>
#include <string>


class Article {
public:
    Article(std::string pModel, double pNetPrice, double pTaxRate = 19)
        : model{pModel} , netPrice{pNetPrice} , taxRate{pTaxRate}
    {

    }

    std::string get_model() {
        return model;
    }

    double get_netPrice() {
        return netPrice;
    }

    double get_grossPrice() {
        double tax = netPrice * taxRate / 100.0;
        return netPrice + tax;
    }

    void set_model(std::string pModel) {
        model = pModel;
    }

    void set_netPrice(double pNetPrice) {
        netPrice = pNetPrice;
    }

    virtual void print() = 0;

    virtual ~Article() {
        std::cout << "~Article()" << " " << model;
    }

private:
    std::string model;
    double netPrice;
    double taxRate;
};


class Accessory : public Article {
public:
    Accessory(std::string pArticleName, double pNetPrice, bool pOriginal = true)
        : Article{pArticleName, pNetPrice} , original{pOriginal}
    {}

    virtual void print() {
        std::cout << Article::get_model();
        if (original)
            std::cout << " " << "(original accessory)";
    }

    virtual ~Accessory() {
        std::cout << "~Accessory()";
        std::cout << " ";
    }
private:
    bool original;
};


enum class OperatingSystem {
    unknown,
    android,
    iOS,
    macOS,
    linux,
    proprietary,
    unix,
    windows
};


std::ostream& operator << (std::ostream& stream, OperatingSystem os) {
    switch (os) {
    case OperatingSystem::unknown:
        stream << "unknown OS";
        break;
    case OperatingSystem::android:
        stream << "Android OS";
        break;
    case OperatingSystem::iOS:
        stream << "iOS";
        break;
    case OperatingSystem::macOS:
        stream << "MacOS";
        break;
    case OperatingSystem::linux:
        stream << "Linux OS";
        break;
    case OperatingSystem::proprietary:
        stream << "proprietary OS";
        break;
    case OperatingSystem::unix:
        stream << "Unix OS";
        break;
    case OperatingSystem::windows:
        stream << "MS Windows OS";
        break;
    }
    return stream;
}


class Device : public Article {
public:
    Device(std::string pArticleName, double pNetPrice, int pMainMemory, OperatingSystem pOS = OperatingSystem::unknown)
            : Article{pArticleName, pNetPrice} , main_memory{pMainMemory} , os{pOS}
    {}

    OperatingSystem get_os() {
        return os;
    }

    virtual void print() {
        std::cout << get_model() << ", " << "RAM " << main_memory << "GB, " << get_os();
    }

    virtual ~Device() {
        std::cout << "~Device()" << " ";
    }

private:
    int main_memory;
    OperatingSystem os;
};


class NoteBook : public Device {
public:
    NoteBook(std::string pArticleName, double pNetPrice, int pMainMemory, std::string pDrive, OperatingSystem pOS = OperatingSystem::linux, bool pConvertible = false)
            : Device{std::move(pArticleName), pNetPrice, pMainMemory, pOS} , drive{std::move(pDrive)} , convertible{pConvertible}
    {

    }

    bool is_a_convertible() {
        return convertible;
    }

    virtual void print() {
        Device::print();
        if (is_a_convertible())
            std::cout << "(convertible)" << ", " << drive;
        else
            std::cout << ", " << drive;
    }

    virtual ~NoteBook() {
        std::cout << "~Notebook()" << " ";
    }
private:
    std::string drive;
    bool        convertible;
};


class Phone : public Device
{
public:
    Phone(std::string pArticleName, double pNetPrice, int pMainMemory = 4, OperatingSystem pOS = OperatingSystem::android)
            : Device{std::move(pArticleName), pNetPrice, pMainMemory, pOS}
    {

    }

    virtual void print() {
        Device::print();
        std::cout << " " << "phone";
    }

    virtual ~Phone() {
        std::cout << "~Phone()" << " ";
    }
};


class InCart {
public:
    InCart(Article* pArticle, int pAmount = 0, InCart* pNext = nullptr)
            : article{pArticle} , amount{pAmount} , next{pNext}
    {

    }

    InCart* get_next() {
        return next;
    }

    virtual void print() {
        double total = article->get_grossPrice() * amount;

        std::cout << amount;
        std::cout << " ";
        article->print();
        std::cout << std::endl;

        std::cout << std::setw(54) << std::fixed << std::setprecision(2) << article->get_grossPrice();
        std::cout << std::setw(4)  << " EUR";
        std::cout << std::setw(16) << std::fixed << std::setprecision(2) << total;
        std::cout << std::setw(4)  << " EUR";
        std::cout << std::endl;
    }

    virtual ~InCart() {
        std::cout << "~Incart()" << " " << amount << " ";
        delete article;
    }

private:
    Article*    article;
    int         amount;
    InCart*     next;
};


class ShoppingCart
{
public:
    ShoppingCart()
            : articles{nullptr} , minFreesShipping{1000} , sumNetPrice{0} , sumGrossPrice{0}
    {

    }

    ~ShoppingCart() {
        std::cout << "~ShoppingCart()\n";

        for (InCart* i = articles, *j = i ? i->get_next(): nullptr; i; i = j, j = i ? i->get_next(): nullptr) {
            std::cout << "delete article:" << " ";
            delete i;
            std::cout << std::endl;
        }
    }

    void set_minFreeShipping(double pMinFreeShipping) {
        minFreesShipping = pMinFreeShipping;
    }

    void add_article(int amount, Article* article) {
        articles = new InCart{article, amount, articles};
        sumNetPrice += amount * article->get_netPrice();
        sumGrossPrice += amount * article->get_grossPrice();
    }

    virtual void print() {

        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                     "+                        P R O T O - T E C - S H O P                         +\n"
                     "+                     Y O U R   S H O P P I N G C A R T                      +\n"
                     "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";


        for (InCart* i = articles; i; i = i->get_next()) {
            std::cout << " ";
            i->print();
        }

        double tax = sumGrossPrice - sumNetPrice;
        double shipping = sumGrossPrice >= minFreesShipping ? 0.0: 5.90;
        double total = sumGrossPrice + shipping;

        std::cout << std::setw(78)  << "-------------" << std::endl;
        std::cout << std::setw(63) << "sum net price:" << std::setw(11) << sumNetPrice << " " << "EUR" << std::endl;
        std::cout << std::setw(63) << "tax:" << std::setw(11) << tax << " " << "EUR" << std::endl;
        std::cout << std::setw(63) << "sum gross price:" << std::setw(11) << sumGrossPrice << " " << "EUR" << std::endl;
        std::cout << std::setw(78) << "-------------" << std::endl;
        std::cout << std::setw(63) << "shipping:" << std::setw(11) << shipping << " " << "EUR" << std::endl;
        std::cout << std::setw(78) << "-------------" << std::endl;
        std::cout << std::setw(63) <<  "total:" << std::setw(11) << total << " " << "EUR" << std::endl;
        std::cout << std::setw(78) << "=============" << std::endl;
    }

private:
    InCart* articles;
    double  minFreesShipping;
    double  sumNetPrice;
    double  sumGrossPrice;
};


int main()
{
    ShoppingCart cart{};
    cart.set_minFreeShipping(500);

    cart.add_article(3, new Accessory{"YOOLOX 10k Wireless Powerbank Qi", 31.08, false});
    cart.print();

    std::cout << std::endl;

    cart.add_article(1, new Phone{"Samsung Galaxy S10+ SM-G975F/DS Dual SIM", 661.67, 8, OperatingSystem ::android});
    cart.add_article(2, new Phone{"Apple iPhone 11 Pro 256GB",  1097.47, 4, OperatingSystem::iOS});
    cart.add_article(1, new NoteBook{"ASUS ROG Strix Scar III G731", 1586.55, 16, "512GB SSD + 1TB SSHD", OperatingSystem::windows});
    cart.print();

    return 0;
}
