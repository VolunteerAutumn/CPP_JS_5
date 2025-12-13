class Circle {
    constructor(radius) {
        this._radius = radius;
    }

    get radius() {
        return this._radius;
    }

    set radius(value) {
        if (value > 0) this._radius = value;
    }

    get diameter() {
        return this._radius * 2;
    }

    area() {
        return Math.PI * this._radius * this._radius;
    }

    circumference() {
        return 2 * Math.PI * this._radius;
    }
}

const circle = new Circle(5);
console.log("Circle radius:", circle.radius);
console.log("Circle diameter:", circle.diameter);
console.log("Circle area:", circle.area());
console.log("Circle circumference:", circle.circumference());

class HtmlElement {
    constructor(tag, selfClosing = false, text = "") {
        this.tag = tag;
        this.selfClosing = selfClosing;
        this.text = text;
        this.attributes = {};
        this.styles = {};
        this.children = [];
    }

    setAttribute(name, value) {
        this.attributes[name] = value;
    }

    setStyle(name, value) {
        this.styles[name] = value;
    }

    addChild(child) {
        this.children.push(child);
    }

    addChildAtStart(child) {
        this.children.unshift(child);
    }

    getHtml() {
        let attrStr = Object.entries(this.attributes)
            .map(([k, v]) => `${k}="${v}"`).join(' ');

        let styleStr = Object.entries(this.styles)
            .map(([k, v]) => `${k}: ${v};`).join(' ');

        if (styleStr) {
            attrStr += (attrStr ? ' ' : '') + `style="${styleStr}"`;
        }

        if (this.selfClosing) {
            return `<${this.tag} ${attrStr} />`;
        }

        let childrenHtml = this.children.map(c => c.getHtml()).join('');
        return `<${this.tag} ${attrStr}>${this.text}${childrenHtml}</${this.tag}>`;
    }
}

class CssClass {
    constructor(name) {
        this.name = name;
        this.styles = {};
    }

    setStyle(prop, value) {
        this.styles[prop] = value;
    }

    removeStyle(prop) {
        delete this.styles[prop];
    }

    getCss() {
        const styleStr = Object.entries(this.styles)
            .map(([k, v]) => `    ${k}: ${v};`).join('\n');
        return `.${this.name} {\n${styleStr}\n}`;
    }
}

class HtmlBlock {
    constructor(rootElement) {
        this.root = rootElement;
        this.cssClasses = [];
    }

    addCssClass(cssClass) {
        this.cssClasses.push(cssClass);
    }

    getCode() {
        const cssCode = this.cssClasses.map(c => c.getCss()).join('\n');
        return `<style>\n${cssCode}\n</style>\n${this.root.getHtml()}`;
    }
}

const wrapper = new HtmlElement('div');
wrapper.setAttribute('id', 'wrapper');
wrapper.setAttribute('class', 'wrap');

function createBlock() {
    const block = new HtmlElement('div');
    block.setAttribute('class', 'block');

    const h3 = new HtmlElement('h3', false, 'What is Lorem Ipsum?');
    block.addChild(h3);

    const img = new HtmlElement('img', true);
    img.setAttribute('class', 'img');
    img.setAttribute('src', 'lipsum.jpg');
    img.setAttribute('alt', 'Lorem Ipsum');
    block.addChild(img);

    const p = new HtmlElement('p', false, `"Lorem Ipsum is simply dummy text of the printing and typesetting industry..."`);
    p.setAttribute('class', 'text');
    const a = new HtmlElement('a', false, 'More...');
    a.setAttribute('href', 'https://www.lipsum.com/');
    a.setAttribute('target', '_blank');
    p.addChild(a);

    block.addChild(p);
    return block;
}

wrapper.addChild(createBlock());
wrapper.addChild(createBlock());

const wrapCss = new CssClass('wrap');
wrapCss.setStyle('display', 'flex');

const blockCss = new CssClass('block');
blockCss.setStyle('width', '300px');
blockCss.setStyle('margin', '10px');

const imgCss = new CssClass('img');
imgCss.setStyle('width', '100%');

const textCss = new CssClass('text');
textCss.setStyle('text-align', 'justify');

const htmlBlock = new HtmlBlock(wrapper);
htmlBlock.addCssClass(wrapCss);
htmlBlock.addCssClass(blockCss);
htmlBlock.addCssClass(imgCss);
htmlBlock.addCssClass(textCss);

document.write(htmlBlock.getCode());
