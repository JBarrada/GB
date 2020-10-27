unsigned int keys[2] = {0x0f, 0x0f};
unsigned int colidx = 0;

extern inline unsigned char inportb(unsigned int port);

void key_reset() {
	keys[0] = 0x0f;
	keys[1] = 0x0f;
	colidx = 0;
}

unsigned char key_rb() {
	update_keys();
	switch (colidx) {
		case 0x00:
			return 0x00;
			
		case 0x10:
			return keys[0];
			
		case 0x20:
			return keys[1];
			
		default:
			return 0x00;
	}
}

void key_wb(unsigned int v) {
	colidx = v&0x30;
}

void update_keys() {
	int scancode = inportb(0x60);
	if ((scancode & 0x80) ^ 0x80) {
		switch (scancode&0x7f) {
			case 0x4d: keys[1] &= 0xE; break; // right
			case 0x4b: keys[1] &= 0xD; break; // left
			case 0x48: keys[1] &= 0xB; break; // up
			case 0x50: keys[1] &= 0x7; break; // down
			case 0x2c: keys[0] &= 0xE; break; // a
			case 0x2d: keys[0] &= 0xD; break; // b
			case 0x39: keys[0] &= 0xB; break; // select
			case 0x1c: keys[0] &= 0x7; break; // start
		}
	}
	else {
		keys[0] = 0x0f;
		keys[1] = 0x0f;
	}
}

/*
  keydown: function(e) {
    switch(e.keyCode)
    {
      case 39: KEY._keys[1] &= 0xE; break;
      case 37: KEY._keys[1] &= 0xD; break;
      case 38: KEY._keys[1] &= 0xB; break;
      case 40: KEY._keys[1] &= 0x7; break;
      case 90: KEY._keys[0] &= 0xE; break;
      case 88: KEY._keys[0] &= 0xD; break;
      case 32: KEY._keys[0] &= 0xB; break;
      case 13: KEY._keys[0] &= 0x7; break;
    }
  }

  keyup: function(e) {
    switch(e.keyCode)
    {
      case 39: KEY._keys[1] |= 0x1; break;
      case 37: KEY._keys[1] |= 0x2; break;
      case 38: KEY._keys[1] |= 0x4; break;
      case 40: KEY._keys[1] |= 0x8; break;
      case 90: KEY._keys[0] |= 0x1; break;
      case 88: KEY._keys[0] |= 0x2; break;
      case 32: KEY._keys[0] |= 0x4; break;
      case 13: KEY._keys[0] |= 0x8; break;
    }
  }
*/
