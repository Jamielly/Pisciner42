/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:35:42 by mmaquine          #+#    #+#             */
/*   Updated: 2025/06/08 16:29:08 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void initialize_array(char *arr, int items)
{
  int index;
  
  index = 0;
  while(index < items)
  {
    arr[index] = '\0';
    index++; 
  }
}

void ft_putstr(char *str)
{
  while(*str)
    write(1, str++, 1);
}

void ft_putmatrix(char *str, int size)
{
  int index = 0;
  while(index < size * size)
  {
    write(1, &str[index], 1);
    if(index % size == size -1)
      write(1, "\n", 1);
    index++;
  }
}

void initialize_array2(unsigned char *arr, int items)
{
  int index;
  
  index = 0;
  while(index < items)
  {
    arr[index] = '\0';
    index++; 
  }
}

void ft_putchar(char c)
{
  write(1, &c, 1);
}



int is_right_visibility_valid(int size, char *data, int visibility, int position)
{
  int index;
  char max_value;
  int count;
  char value;
  
  count = 0;
  max_value = 0;
  value = '\0';
  index = size - 1;
  
  while(index >= 0)
  {
    value = data[position / size * size + index];
    if(max_value < value )
    {
      max_value = value;
      count++;
    }
    index--;
  }
  return (count <= visibility);
}

int is_left_visibility_valid(int size, char *data, int visibility, int position)
{
  int index;
  char max_value;
  int count;
  char value;
  
  count = 0;
  max_value = 0;
  value = '\0';
  index = 0;
  
  while(index < size)
  {
    value = data[position / size * size + index];
    if(max_value < value )
    {
      max_value = value;
      count++;
    }
    index++;
  }
  return (count <= visibility);
}

int is_top_visibility_valid(int size, char *data, int visibility, int position)
{
  int index;
  char max_value;
  int count;
  char value;
  
  count = 0;
  max_value = 0;
  value = '\0';
  index = 0;
  
  while(index < size)
  {
    value = data[(position % size) + (index * size)];
    if(max_value < value )
    {
      max_value = value;
      count++;
    }
    index++;
  }
  return (count <= visibility);
}

int is_bottom_visibility_valid(int size, char *data, int visibility, int position)
{
  int index;
  char max_value;
  int count;
  char value;
  
  count = 0;
  max_value = 0;
  value = '\0';
  index = size - 1;
  
  while(index >= 0)
  {
    value = data[(position % size) + (size * index)];
    if(max_value < value )
    {
      max_value = value;
      count++;
    }
    index--;
  }
  return (count <= visibility);
}



int is_distinct_in_row(int size, char *data, int position)
{
  int index;
  unsigned char value;
  unsigned char map[256];

  initialize_array2(map, 256);
  value = '\0';
  index = 0;
  while(index < size)
  {
    value = (unsigned char) data[position / size * size + index];
    if(!value) 
    {
      index++;
      continue;
    }
    if (map[value] == 1)
    {
      return (0);
    }
    map[value] = 1;
    index++;
  }
  return (1);
}

int is_distinct_in_col(int size, char *data, int position)
{
  int index;
   unsigned char value;
  unsigned char map[256];

  initialize_array2(map, 256);
  
  value = '\0';
  index = 0;
  
  while(index < size)
  {
    value = (unsigned char) data[(position % size) + (index * size)];
    if(!value) 
    {
      index++;
      continue;
    }
    if (map[value] == 1)
    {
      return (0);
    }
    map[value] = 1;
    index++;
  }
  return (1);
}