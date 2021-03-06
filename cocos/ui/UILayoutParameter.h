/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __LAYOUTPARMETER_H__
#define __LAYOUTPARMETER_H__

#include <string>
#include "base/CCRef.h"


NS_CC_BEGIN

namespace ui {

/**
 *   @js NA
 *   @lua NA
 */
class Margin
{
public:
    float left;
    float top;
    float right;
    float bottom;
    
public:
    Margin();
    Margin(float l, float t, float r, float b);
    Margin(const Margin& other);
    Margin& operator= (const Margin& other);
    void setMargin(float l, float t, float r, float b);
    bool equals(const Margin& target) const;
};

const Margin MarginZero = Margin();

/**
*   @js NA
*   @lua NA
*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#ifdef RELATIVE
#undef RELATIVE
#endif
#endif

class LayoutParameter : public Ref
{
public:
    enum class Type
    {
        NONE = 0,
        LINEAR,
        RELATIVE
    };
    /**
     * 默认构造函数（constructor）
     */
    LayoutParameter() : _margin(Margin())
    {
        _layoutParameterType = Type::NONE;
    };
    
    /**
     * 默认析构函数（destructor）
     */
    virtual ~LayoutParameter(){};
    
    /**
     * 分配（Allocates）并初始化（initializes）
     * @return 一个已初始化的LayoutParameter，标记为 "autorelease"
     */
    static LayoutParameter* create();
    
    /**
     * 为LayoutParameter设置外边距参数（Margin parameter）
     * 
     * @see Margin
     *
     * @param 外边距
     */
    void setMargin(const Margin& margin);
    
    /**
     * 获取LayoutParameter的外边距参数（Margin parameter）
     *
     * @see Margin
     *
     * @return const Margin&
     */
    const Margin& getMargin() const;
    
    /**
     * 获取LayoutParameter的LayoutParameterType
     *
     * @see LayoutParameterType
     *
     * @return LayoutParameterType
     */
    Type getLayoutType() const;
    
    LayoutParameter* clone();
    virtual LayoutParameter* createCloneInstance();
    virtual void copyProperties(LayoutParameter* model);
protected:
    Margin _margin;
    Type _layoutParameterType;
};

    
/**
*   @js NA
*   @lua NA
*/
class LinearLayoutParameter : public LayoutParameter
{
public:
    enum class LinearGravity
    {
        NONE,
        LEFT,
        TOP,
        RIGHT,
        BOTTOM,
        CENTER_VERTICAL,
        CENTER_HORIZONTAL
    };
    /**
     * 默认构造函数（constructor）
     */
    LinearLayoutParameter()
    : _linearGravity(LinearGravity::NONE)
    {
        _layoutParameterType = Type::LINEAR;
    };
    
    /**
     * 默认析构函数（destructor）
     */
    virtual ~LinearLayoutParameter(){};
    
    /**
     * 分配（Allocates）并初始化（initializes.）
     * @return    一个已初始化的LayoutParameter， 标记为 "autorelease".
     */
    static LinearLayoutParameter* create();
    
    /**
     * 为LayoutParameter设置LinearGravity参数
     *
     * @see LinearGravity
     *
     * @param LinearGravity
     */
    void setGravity(LinearGravity gravity);
    
    /**
     * 获取LayoutParameter的LinearGravity参数
     *
     * @see LinearGravity
     *
     * @return LinearGravity
     */
    LinearGravity getGravity() const;
    virtual LayoutParameter* createCloneInstance() override;
    virtual void copyProperties(LayoutParameter* model) override;
protected:
    LinearGravity _linearGravity;
};
    
    
/**
*   @js NA
*   @lua NA
*/

    
class RelativeLayoutParameter : public LayoutParameter
{
public:
    enum class RelativeAlign
    {
        NONE,
        PARENT_TOP_LEFT,
        PARENT_TOP_CENTER_HORIZONTAL,
        PARENT_TOP_RIGHT,
        PARENT_LEFT_CENTER_VERTICAL,
        
        CENTER_IN_PARENT,
        
        PARENT_RIGHT_CENTER_VERTICAL,
        PARENT_LEFT_BOTTOM,
        PARENT_BOTTOM_CENTER_HORIZONTAL,
        PARENT_RIGHT_BOTTOM,
        
        LOCATION_ABOVE_LEFTALIGN,
        LOCATION_ABOVE_CENTER,
        LOCATION_ABOVE_RIGHTALIGN,
        LOCATION_LEFT_OF_TOPALIGN,
        LOCATION_LEFT_OF_CENTER,
        LOCATION_LEFT_OF_BOTTOMALIGN,
        LOCATION_RIGHT_OF_TOPALIGN,
        LOCATION_RIGHT_OF_CENTER,
        LOCATION_RIGHT_OF_BOTTOMALIGN,
        LOCATION_BELOW_LEFTALIGN,
        LOCATION_BELOW_CENTER,
        LOCATION_BELOW_RIGHTALIGN
    };
    /**
     * 默认构造函数（constructor）
     */
    RelativeLayoutParameter()
    : _relativeAlign(RelativeAlign::NONE),
    _relativeWidgetName(""),
    _relativeLayoutName(""),
    _put(false)
    {
        _layoutParameterType = Type::RELATIVE;
    };
    
    /**
     * 默认析构函数（destructor）
     */
    virtual ~RelativeLayoutParameter(){};
    
    /**
     * 分配（Allocates）并初始化（initializes）.
     * @return 一个已初始化的 LayoutParameter ，标记为 "autorelease".
     */
    static RelativeLayoutParameter* create();
    
    /**
     * 为LayoutParameter设置RelativeAlign参数
     *
     * @see RelativeAlign
     *
     * @param RelativeAlign
     */
    void setAlign(RelativeAlign align);
    
    /**
     * 获取LayoutParameter的RelativeAlign参数
     *
     * @see RelativeAlign
     *
     * @return RelativeAlign
     */
    RelativeAlign getAlign() const;
    
    /**
     * 设置LayoutParameter的key. 相应的widget相对于此命名.
     *
     * @param name
     */
    void setRelativeToWidgetName(const std::string& name);
    
    /**
     * 获取LayoutParameter的key. 相应的widget相对于此命名.
     *
     * @return name
     */
    const std::string& getRelativeToWidgetName() const;
    
    /**
     * 为LayoutParameter在相对布局（Relative Layout）中设置一个name。
     *
     * @param name
     */
    void setRelativeName(const std::string& name);
    
    /**
     * 获取LayoutParameter在相对布局（Relative Layout）中的name。
     *
     * @return name
     */
    const std::string& getRelativeName() const;
    
    virtual LayoutParameter* createCloneInstance() override;
    virtual void copyProperties(LayoutParameter* model) override;
protected:
    RelativeAlign _relativeAlign;
    std::string _relativeWidgetName;
    std::string _relativeLayoutName;
    bool _put;
    friend class RelativeLayoutExecutant;
};

}

NS_CC_END

#endif /* defined(__LayoutParameter__) */
