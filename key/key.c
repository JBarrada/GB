unsigned int keys[2] = {0x0f, 0x0f};
unsigned int colidx = 0;

void key_reset() {
	keys[0] = 0x0f;
	keys[1] = 0x0f;
	colidx = 0;
}

unsigned char key_rb() {
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