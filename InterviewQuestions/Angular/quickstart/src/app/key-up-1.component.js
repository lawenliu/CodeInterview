"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var core_1 = require("@angular/core");
var KeyUpComponent_v1 = (function () {
    function KeyUpComponent_v1() {
        this.values = "";
    }
    KeyUpComponent_v1.prototype.update = function (value) {
        this.values = value;
    };
    return KeyUpComponent_v1;
}());
KeyUpComponent_v1 = __decorate([
    core_1.Component({
        selector: 'key-up',
        template: "\n\t\t<input #box\n\t\t  (keyup.enter)=\"update(box.value)\"\n\t\t  (blur)=\"update(box.value)\">\n\t\t<p>{{values}}</p>\n\t"
    })
], KeyUpComponent_v1);
exports.KeyUpComponent_v1 = KeyUpComponent_v1;
//# sourceMappingURL=key-up-1.component.js.map