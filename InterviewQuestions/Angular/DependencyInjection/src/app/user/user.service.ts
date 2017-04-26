import { Injectable } from '@angular/core';

import { USER } from './mock-user';

@Injectable()
export class UserService {
	constructor() {}

	getUser() {
		return USER;
	}
}
