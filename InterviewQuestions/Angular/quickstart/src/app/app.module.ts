import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';

import { AppComponent } from './app.component';
import { ClickMeComponent } from './click-me.component';
import { KeyUpComponent_v1 } from './key-up-1.component';
import { LittleTourComponent } from './little-tour.component';
import { HeroFormComponent } from './hero-form.component';

@NgModule({
	imports: [
		BrowserModule,
		FormsModule
	],
	declarations: [
		AppComponent,
		ClickMeComponent,
		KeyUpComponent_v1,
		LittleTourComponent,
		HeroFormComponent
	],
	bootstrap: [AppComponent]
})

export class AppModule {}
