import { Component } from '@angular/core';

@Component({
	selector: 'key-up',
	template: `
		<input #box
		  (keyup.enter)="update(box.value)"
		  (blur)="update(box.value)">
		<p>{{values}}</p>
	`
})

export class KeyUpComponent_v1 {
	values = "";
	update(value: string) {
		this.values = value;
	}
}

