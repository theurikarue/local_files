
import './App.css'
import Person from "./Person.tsx"

function App() {
 
  return (
    <>
      <Person name={"Pedro"} age={21} isMarried={false}/>
      <Person name={"Muthoni"} age={27} isMarried={true}/>
    </>
  )
}

export default App
