import { Component } from '@angular/core';

import { Hero } from './hero';
import { HeroService } from './hero.service';

@Component({
	selector: 'hero-list',
	template: `
		<h1>Hero List:</h1>
		<div *ngFor="let hero of heroes">
			{{hero.id}} - {{hero.name}}
		</div>
	`
})

export class HeroListComponent {
	heroes: Hero[];

	constructor(heroService: HeroService) {
		this.heroes = heroService.getHeroes();
	}
}
