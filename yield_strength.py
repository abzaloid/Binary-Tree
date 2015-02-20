
gravity = 9.81
max_mass = 7

power = 1000

b1 = 38 * power
b2 = 83 * power
b3 = 83 * power
h = 250 * power
l = 210 * power
w = 56 * gravity * power
wh = 1581 * gravity * power
wm = 55 * gravity * power
F = max_mass * gravity


a = 37
y = a / 2
I = (a**4) / 12

sum_len = b1 + b2 + b3 + h + 2 * l

M = F * sum_len + \
	wm * (sum_len - h) + \
	wm * (sum_len - h - b3) + \
	w * (sum_len - h - b3 - l/2) + \
	wm * (sum_len - h - b3 - l) + \
	wm * (sum_len - h - b3 - l - b2) + \
	w * (sum_len - h - b3 - l - b2 - l/2) + \
	wm * (sum_len - h - b3 - l - b2 - l)

Gg = (M * y / I) / 1000000
yield_strength = 414

print 'tensile stress =', Gg, 'MPa'
print 'safety factor', yield_strength / Gg
