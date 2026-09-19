#include <iostream>
#include <memory>
#include <string>

class Button
{
public:
    virtual ~Button() = default;
    virtual void render() const = 0;
};

class CheckBox
{
public:
    virtual ~CheckBox() = default;
    virtual void render() const = 0;
};

class LightButton : public Button
{
public:
    void render() const override
    {
        std::cout << "Rendering light theme button" << std::endl;
    }
};

class LightCheckBox : public CheckBox
{
public:
    void render() const override
    {
        std::cout << "Rendering light theme checkbox" << std::endl;
    }
};

class DarkButton : public Button
{
public:
    void render() const override
    {
        std::cout << "Rendering dark theme button" << std::endl;
    }
};

class DarkCheckBox : public CheckBox
{
public:
    void render() const override
    {
        std::cout << "Rendering dark theme checkbox" << std::endl;
    }
};

class UIWidgetFactory
{
public:
    virtual ~UIWidgetFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<CheckBox> createCheckBox() const = 0;
};

class LightThemeFactory : public UIWidgetFactory
{
public:
    std::unique_ptr<Button> createButton() const override
    {
        return std::make_unique<LightButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() const override
    {
        return std::make_unique<LightCheckBox>();
    }
};

class DarkThemeFactory : public UIWidgetFactory
{
public:
    std::unique_ptr<Button> createButton() const override
    {
        return std::make_unique<DarkButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() const override
    {
        return std::make_unique<DarkCheckBox>();
    }
};

int main()
{
    std::cout << "Abstract Factory Pattern Example" << std::endl;

    std::unique_ptr<UIWidgetFactory> lightFactory = std::make_unique<LightThemeFactory>();
    auto lightButton = lightFactory->createButton();
    auto lightCheckBox = lightFactory->createCheckBox();

    lightButton->render();
    lightCheckBox->render();

    std::cout << std::endl;

    std::unique_ptr<UIWidgetFactory> darkFactory = std::make_unique<DarkThemeFactory>();
    auto darkButton = darkFactory->createButton();
    auto darkCheckBox = darkFactory->createCheckBox();

    darkButton->render();
    darkCheckBox->render();

    return 0;
}
