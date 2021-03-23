For each training set:
  probability_m = 1
  probability_r = 1
  for each attribute as attr:
    if(attribute_value <= mi):
      probability_metal *= probabilty(attribute_value, low[attr]["metal_mean"], low[attr]["metal_deviation"])
      probability_rock *=  probabilty(attribute_value, low[attr]["rock_mean"], low[attr]["rock_deviation"])
    else:
      probability_metal *= probabilty(attribute_value, high[attr]["metal_mean"], high[attr]["metal_deviation"])
      probability_rock *=  probabilty(attribute_value, high[attr]["rock_mean"], high[attr]["rock_deviation"])

  if(probabilty_metal > probability_rock):
    predict_test_case as metal
  else:
    predict_test_case as rock



li = list of mi for each attribute
For each attribute in data as attr:
  min_attr , max_attr = minimum(attr) , maximum(attr)

  rate = 0.00001 ( rate <<< 1 )
  gain = 0
  result = min_attr
  while(min_attr < max_attr):
    divide attribute set at min_attr
    find gain ratio
    if(gain_temp > gain):
      gain =temp_gain
      result = min_attr
    min_attr += rate

  li[attr] = result



