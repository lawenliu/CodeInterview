"use strict";
var __extends = (this && this.__extends) || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
};
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var core_1 = require("@angular/core");
var logger_service_1 = require("./logger.service");
var user_service_1 = require("./user/user.service");
var EvenBetterLogger = (function (_super) {
    __extends(EvenBetterLogger, _super);
    function EvenBetterLogger(userService) {
        var _this = _super.call(this) || this;
        _this.userService = userService;
        return _this;
    }
    EvenBetterLogger.prototype.log = function (message) {
        var name = this.userService.getUser().name;
        _super.prototype.log.call(this, "Message to " + name + ": " + message);
    };
    return EvenBetterLogger;
}(logger_service_1.Logger));
EvenBetterLogger = __decorate([
    core_1.Injectable(),
    __metadata("design:paramtypes", [user_service_1.UserService])
], EvenBetterLogger);
exports.EvenBetterLogger = EvenBetterLogger;
//# sourceMappingURL=evenbetterlogger.service.js.map