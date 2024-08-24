import { useState } from 'react'

const Counter=()=> {
  const [count, setCount] = useState(0)

  function addOne() {
    setCount(count + 1)
  }
  return (
    <>
      <button onClick={addOne}>Count={count}</button>
    </>
  )
}


import React from 'react'

const NameList = () => {
  const [list,setList] = useState(["Jane","Jack","Jill"])
  const [name,setName,] = useState("")

  // const onAddName=()=>{
  //   list.push(name)
  // }
  // in the above case one will need to use setList([...list,name]) to update the list or else the list won't be update
  // automatically it'll only be updated when the component is re-rendered. Thisis because objects, arrays give back the 
  //reference of the array and not the values in the array so react doesn't know that the array has been updated
  // However, Strings Booleans and numbers are scalers and they give back the value and not the reference so react knows. 

  const onAddName=()=>{
      setList([...list, name]) // this will update the list and re-render the component
    }

  return (
    <div>
      <ul>
        {list.map((name)=>(
          <li>{name}</li>
          ))}
      </ul>
      <input type="text" value={name} onChange={(e)=>setName(e.target.value)} />
      <button onClick={onAddName} >Add Name</button>
    </div>
  )
}

const App = () => {
  return (
    
    <div>
      <Counter/>
      <NameList/>
    </div>
  )
}

export default App
